#include "News.h"
#include "Reaction.h"

News::News()
{

}

News::News(string title, string text, vector<string> comments, string media, string field)
{
    news_title = title;
    news_text = text;
    news_comments = comments;
    news_categories.insert({ "언론사", media });
    news_categories.insert({ "분야", field });
}

string News::getNewsTitle() const
{
    return news_title;
}

string News::getNewsText() const
{
    return news_text;
}

vector<string> News::getNewsComments() const
{
    return news_comments;
}

map<string, string> News::getCategory() const
{
    return news_categories; 
}

string News::getSubcategory(string category) const
{
    if (news_categories.find(category) == news_categories.end())
    {
        return "";
    }
    return news_categories.find(category)->second;
}


void News::filterSpamComment(const vector<string>& fwords)
{
    for (int i = 0; i < news_comments.size(); ++i)
    {
        for (int j = 0; j < fwords.size(); ++j)
        {
            if (news_comments[i].find(fwords[j]) != string::npos)
            {
                news_comments[i] = "필터링되었습니다!!!!";
                break;
            }
        }
    }
    return;
}
// filter comment that contains fword

void News::testNews()
{
    vector<string> test_fword = { "FFFF" };
    vector<string> test_comment = { "comment1", "FFFF" };
    News test_news = News("title", "text", test_comment, "media", "field");
    test_comment.clear();
    test_news.filterSpamComment(test_fword);
    
    cout << test_news.getNewsTitle() << endl;
    cout << test_news.getNewsText() << endl;
    cout << test_news.getSubcategory("언론사") << endl;
    cout << test_news.getSubcategory("분야") << endl;

    test_comment = test_news.getNewsComments();
    for (int i = 0; i < test_comment.size(); ++i)
    {
        cout << test_comment[i] << endl;
    }
}



