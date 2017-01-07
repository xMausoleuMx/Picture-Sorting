#include "container.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;



struct image{
	string path;
	unsigned int score = 0;
};

vector<image> merge(vector<image> listOne, vector<image> listTwo);

vector<image> sortPics(vector<image> list)
{
	if (list.size() <= 1)
		return list;
	vector<image> left, right, sorted;
	for (int i = 0; i < list.size() / 2; i++)
		left.push_back(list[i]);
	for (int z = list.size() / 2; z < list.size(); z++)
		right.push_back(list[z]);
	left = sortPics(left);
	right = sortPics(right);
	sorted = merge(left, right);
	
}

vector<image> merge(vector<image> listOne, vector<image> listTwo)
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

void main()
{
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);
	//PictureSorting::container container;
	//Application::Run(%container);


	vector<image> tester;
	for (int i = 0; i < 100; i++)
	{
		image test;
		test.score = rand();
		cout << test.score << endl;
		tester.push_back(test);
	}
	tester = sortPics(tester);
	for (int i = 0; i < tester.size(); i++)
		cout << tester[i].score << endl;

	cout << tester.size();
}