#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Collections;


static struct image{
	string path;
	int score = 0;
	int comparisons = 0;
	double rating;
};

static struct setting{
	string name;
	string path = "";
	bool flag;
};


bool saveFile();
void tempSort(vector<image>* list);
vector<image> mergeImages(vector<image> listOne, vector<image> listTwo);
vector<image> sortPics(vector<image> list);

//uses wilson score to determine rating, should be more accurate than just score/comparisons
static double getRating(image holder)
{
	if (holder.score == 0)
		return 0;
	return(((holder.score + 1.9208) / (holder.score + holder.comparisons) - 1.96 * sqrt(((holder.score * holder.comparisons) / (holder.score + holder.comparisons)) + 0.9604) / (holder.score + holder.comparisons)) / (1 + 3.8416 / (holder.score + holder.comparisons)));
}

//changes a System::String^ to a std::string
static string Stringtostring(System::String^ x){
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(x);
}

//sorting used when continuous sorting and sort by score is checked 
static void continuousScoreSort(vector<image>* list)
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 1; i < (*list).size(); i++)
		{
			if ((*list)[i].score >(*list)[i - 1].score)
			{
				image a = (*list)[i];
				image b = (*list)[i - 1];
				(*list)[i] = b;
				(*list)[i - 1] = a;
				flag = true;
			}
		}
	} while (flag);
}

//sorting used when continuous sorting and sort by rating is checked 
static void continuousRatingSort(vector<image>* list)
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 1; i < (*list).size(); i++)
		{
			if ( getRating((*list)[i]) > getRating((*list)[i-1]))
			{
				image a = (*list)[i];
				image b = (*list)[i - 1];
				(*list)[i] = b;
				(*list)[i - 1] = a;
				flag = true;
			}
		}
	} while (flag);
}

//checks if image is one of the supported formats
static bool checkIfImage(string path)
{
	bool flag = true;
	string extensions[] = { ".gif", ".jpg", ".jpeg", ".bmp", ".wmf", ".png" };
	for (int i = 0; i < 6; i++)
	{
		flag = true;
		for (int y = extensions[i].size() - 1; y >= 0; y--)
		{
			if (path[path.size() - y] != extensions[i][extensions[i].size() -y])
				flag = false;
		}
		if (flag)
			return true;
	}
	return flag;
}

//recursively searches the given directory for valid image files
static vector<image> getFiles(System::String^ directory)
{
	vector<image> list, temp;
	string inputFolderPath = Stringtostring(directory);
	System::String^ path = gcnew System::String(directory);
	array<System::String^>^fileEntries = Directory::GetFiles(path);
	IEnumerator^ files = fileEntries->GetEnumerator();
	while (files->MoveNext())
	{
		String^ fileName = safe_cast<String^>(files->Current);
		image temp;
		temp.path = Stringtostring(fileName);
		if (checkIfImage(temp.path))
			list.push_back(temp);
	}	
	array<System::String^>^folderEntries = Directory::GetDirectories(path); 
	IEnumerator^ dirs = folderEntries->GetEnumerator();
	while (dirs->MoveNext())
	{
		String^ subDir = safe_cast<String^>(dirs->Current);
		temp = getFiles(subDir);
		list.insert(list.end(), temp.begin(), temp.end());
	}
	return list;
}

//checks to make sure the file is still valid, used when loading a collection
static bool validateFile(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

//gets common directory from a list of images, used to exclude it from the top and bottom lists to make them shorter
static string getDirectory(vector<image> list)
{
	image holder = list[0];
	int marker = INT_MAX;
	string directory;
	for (int i = 1; i < list.size(); i++)
	{
		for (int y = 0; y < list[i].path.size(); y++)
		{
			if (y >= holder.path.size())
				break;
			if ((list[i].path[y] != holder.path[y]) && (y < marker)){
				marker = y;
				break;
			}
		}
	}
	directory.assign(list[0].path.c_str(), marker);
	return directory;
}

//mergesort method to sort images by score
static vector<image> scoreMerge(vector<image> left, vector<image> right)
{
	vector<image>holder;
	int i = 0, k = 0;
	do{
		if((left[i].score > right[k].score)){
			holder.push_back(left[i]);
			i++;
		}
		else{
			holder.push_back(right[k]);
			k++;
		}
	} while (i < left.size() && k < right.size());
	while (i < left.size()){
		holder.push_back(left[i]);
		i++;
	}
	while (k < right.size()){
		holder.push_back(right[k]);
		k++;
	}
	return holder;
}

static void scoreSort(vector<image>* list)
{
	if (list->size() <= 1)
		return;
	vector<image> left, right;
	left.assign(list->begin(), list->begin() + ((list->size()) / 2));
	right.assign(list->begin() + (list->size() / 2), list->end());
	scoreSort(&left);
	scoreSort(&right);
	(*list) = scoreMerge(left, right);
	return;
}


//mergesort method to sort images by rating
static vector<image> ratingMerge(vector<image> left, vector<image> right)
{
	vector<image>holder;
	int i = 0, k = 0;
	do{
		if ((getRating(left[i])) > (getRating(right[k]))){
			holder.push_back(left[i]);
			i++;
		}
		else{
			holder.push_back(right[k]);
			k++;
		}
	} while (i < left.size() && k < right.size());
	while (i < left.size()){
		holder.push_back(left[i]);
		i++;
	}
	while (k < right.size()){
		holder.push_back(right[k]);
		k++;
	}
	return holder;
}

static void ratingSort(vector<image>* list)
{
	if (list->size() <= 1)
		return;
	vector<image> left, right;
	left.assign(list->begin(), list->begin() + ((list->size()) / 2));
	right.assign(list->begin() + (list->size() / 2), list->end());
	ratingSort(&left);
	ratingSort(&right);
	(*list) = ratingMerge(left, right);
	return;
}

