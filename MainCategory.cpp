#include "MainCategory.h"

string MainCategory::getMainCategoryName() const
{
	return main_category_name;
}

vector<Subcategory>& MainCategory::getSubcategories()
{
	return subcategories;
}

void MainCategory::setMainCategoryName(string name)
{
	main_category_name = name;
	return;
}

void MainCategory::setSubcategories(vector<News>& news, const vector<string>& subcategory_names)
{
	for (int i = 0; i < subcategory_names.size(); ++i)
	{
		subcategories.push_back(Subcategory());
		subcategories[i].setSubcategoryName(subcategory_names[i]);
		// save subcategory name
		subcategories[i].setNewsList(news, main_category_name);
		// save news address
	}
	return;
}





