#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<map>
#include "MainCategory.h"
#include "SubCategory.h"
#include "News.h"

using namespace std;

class Display
{
public:
	void printMainCategoriesList(const vector<MainCategory>& main_category);
	void printSubCategoriesList(const vector<Subcategory>& sub_caterory);
	void printSelect(string name);
	void printNewsTitleList(const vector<News*>& news_titles);
	void printNewsReaction(const Reaction& reaction);
	void printNewsElements(const News* news);
};