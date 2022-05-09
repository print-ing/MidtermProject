#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Reaction.h"
using namespace std;

class News
{
private:
    string news_title;
    string news_text;
    map<string, string> news_categories; // e.g. {언론사, KBS}, {분야, 경제}
    vector<string> news_comments;

public:
    Reaction news_reaction;
    News();
    News(string title, string text, vector<string>comments, string field, string media);
    string getNewsTitle() const;
    string getNewsText() const;
    vector<string> getNewsComments() const;
    map<string, string> getCategory() const;
    string getSubcategory(string category) const;
    void filterSpamComment(const vector<string>& fwords);

};


