#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <sstream>

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


static bool checkIfImage(string path)
{
	bool flag = true;
	string extensions[] = { ".gif", "*.jpg", ".jpeg", ".bmp", ".wmf", ".png" };
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

static bool validateFile(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}

static string getDirectory(vector<image> list)
{
	image holder = list[0];
	int marker = 0;
	string directory;
	for (int i = 1; i < list.size(); i++)
	{
		for (int y = 0; y < list[i].path.size(); y++)
		{
			if (y < holder.path.size())
				break;
			if (list[i].path[y] != holder.path[y])
				marker = y - 1;
		}
		holder = list[i];
	}
	directory.assign(list[0].path.c_str(), marker);
	return directory;
}
