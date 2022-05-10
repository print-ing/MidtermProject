#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Subcategory.h"

class MainCategory
{
private:
    string main_category_name;
    vector<Subcategory> subcategories;
public:
    string getMainCategoryName() const;
    vector<Subcategory>& getSubcategories();
    void setMainCategoryName(string name);
    void setSubcategories(vector<News>& news, const vector<string>& subcategory_names);

};

