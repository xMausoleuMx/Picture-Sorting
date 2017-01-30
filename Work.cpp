#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Collections;

static struct image{
	string path;
	int score = 0;
};

bool saveFile();
void tempSort(vector<image>* list);
vector<image> mergeImages(vector<image> listOne, vector<image> listTwo);
vector<image> sortPics(vector<image> list);

static void tempSort(vector<image>* list)
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


static vector<image> sortPics(vector<image> list)
{
	if (list.size() <= 1)
		return list;
	vector<image>sorted;
	int midpoint = 0.5*list.size();
	vector<image> left(list.begin(), list.begin() + midpoint);
	vector<image> right(list.begin() + midpoint, list.end());
	left = sortPics(left);
	right = sortPics(right);
	sorted = mergeImages(left, right);
	return sorted;
}


static vector<image> mergeImages(vector<image> listOne, vector<image> listTwo)
{
	vector<image> result;
	while (listOne.size()>0 || listTwo.size() > 0)
	{
		if (listOne.size() > 0 && listTwo.size() > 0) {
			if (listOne.front().score <= listTwo.front().score) {
				result.push_back(listOne.front());
				listOne.erase(listOne.begin());
			}
			else {
				result.push_back(listTwo.front());
				listTwo.erase(listTwo.begin());
			}
		}
		else if (listOne.size() > 0) {
			for (int i = 0; i < listOne.size(); i++)
				result.push_back(listOne[i]);
			break;
		}
		else if (listTwo.size() > 0) {
			for (int i = 0; i < listTwo.size(); i++)
				result.push_back(listTwo[i]);
			break;
		}
	}
	return result;
}

static bool checkIfImage(string path)
{
	bool flag = true;
	//check extension and verify it is a image file
	return flag;
}

static vector<image> getFiles(System::String^ directory)
{
	vector<image> list, temp;
	msclr::interop::marshal_context context;
	string inputFolderPath = context.marshal_as<std::string>(directory);
	System::String^ path = gcnew System::String(directory);
	array<System::String^>^fileEntries = Directory::GetFiles(path);
	IEnumerator^ files = fileEntries->GetEnumerator();
	while (files->MoveNext())
	{
		String^ fileName = safe_cast<String^>(files->Current);
		image temp;
		temp.path = context.marshal_as<std::string>(fileName);
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



