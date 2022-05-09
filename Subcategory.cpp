#include "Subcategory.h"

string Subcategory::getSubcategoryName() const
{
    return subcategory_name;
}

vector<News*>& Subcategory::getSubcategoryNews()
{
    return subcategory_news;
}

void Subcategory::setSubcategoryName(string name)
{
    subcategory_name = name;
    return;
}

void Subcategory::setNewsList(vector<News>& news, string main_category_name)
{
    for (int i = 0; i < news.size(); ++i)
    {
        string news_subcategory_name = news[i].getSubcategory(main_category_name);
        if (subcategory_name == news_subcategory_name)
            // check subcategory name of news and subcategory object
        {
            subcategory_news.push_back(&news[i]);
            // save news address to news address vector
        }
    }
    return;
}


