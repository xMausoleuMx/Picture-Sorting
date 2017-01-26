#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>

using namespace std;



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

static void getFilesList(string filePath, vector<string> & returnFileName)
{
	WIN32_FIND_DATA fileInfo;
	HANDLE hFind;
	string  fullPath = filePath;
	hFind = FindFirstFile((LPCWSTR)(fullPath.c_str()), &fileInfo);
	if (hFind != INVALID_HANDLE_VALUE){
		char ch[260];
		char DefChar = ' ';
		WideCharToMultiByte(CP_ACP, 0, fileInfo.cFileName, -1, ch, 260, &DefChar, NULL);
		returnFileName.push_back(filePath + ch);
		while (FindNextFile(hFind, &fileInfo) != 0){
			char DefChar = ' ';
			WideCharToMultiByte(CP_ACP, 0, fileInfo.cFileName, -1, ch, 260, &DefChar, NULL);
			returnFileName.push_back(filePath + ch);
		}
	}
}

static vector<image> getFiles(const wchar_t* directory)
{
	vector<image> list;
	string optfileName = "";
	wstring ws(directory);
	string inputFolderPath(ws.begin(),ws.end());
	vector<string> filesPaths;
	getFilesList(inputFolderPath, filesPaths);
	int it = 0;
	while (it < filesPaths.size())
	{
		image temp;
		temp.path = filesPaths[it];
		if (checkIfImage(temp.path))
			list.push_back(temp);
		it++;
	}
	return list;
}



