#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "News.h"
#include "Reaction.h"


class Subcategory
{
private:
    string subcategory_name;
    vector<News*> subcategory_news;

public:
    Reaction reaction;
    string getSubcategoryName() const;
    vector<News*>& getSubcategoryNews();
    void setSubcategoryName(string name);
    void setNewsList(vector<News>& news, string main_category_name);
};

