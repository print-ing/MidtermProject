#pragma once
#include<iostream>
#include "MainCategory.h"
#include "Subcategory.h"
#include "News.h"
#include "Reaction.h"
#include "Display.h"

class UserInteraction 
{
public:
	void receiveUserReaction(Reaction& reaction);
	vector<Subcategory>& selectMainCategory(vector<MainCategory>& main_category, Display display);
	Subcategory& SingleSubCategory(vector<Subcategory>& sub_category, Display display);
	News* selectNews(const vector<News*>& selected_news);
	bool isIntegerInput(string input);

	void testIsIntegerInput();
};