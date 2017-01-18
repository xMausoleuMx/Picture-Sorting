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

