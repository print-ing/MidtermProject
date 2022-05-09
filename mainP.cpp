#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include "Reaction.h"
#include "News.h"
#include "MainCategory.h"
#include "Subcategory.h"
#include "Display.h"
#include "UserInteraction.h"
using namespace std;

void readCsvFile(vector<News>& news, vector<string>& fwords);
vector<string> listComments(string comment);
vector<string> readCsvRow(istream& in, char delimiter);
void saveFwords(vector<string>& fwords);

int main()
{
    Display display;
    UserInteraction user_interaction;

    vector<string> fwords;
    saveFwords(fwords);
    vector<News> news;
    readCsvFile(news, fwords);

    int index;
    string index_str;

    vector<string> main_category_names = { "��л�", "�о�" };
    map<string, vector<string>> categories;
    categories.insert({ "��л�", {"SBS", "MBC", "JTBC", "KBS", "�����Ϻ�", "���մ���", "�Ѱܷ�"} });
    categories.insert({ "�о�", {"��ġ", "����", "��ȸ", "��Ȱ/��ȭ", "����" } });
    // for saving main categories and subcategories

    vector<MainCategory> main_categories;
    for (int i = 0; i < main_category_names.size(); ++i)
    {
        main_categories.push_back(MainCategory());
        main_categories[i].setMainCategoryName(main_category_names[i]);
        // save main category name
        vector<string> subcategory_names = categories.find(main_categories[i].getMainCategoryName())->second;
        main_categories[i].setSubcategories(news, subcategory_names);
        // save subcategory name
    }



    cout << "���α׷��� �����ϰ� �����ôٸ� -1�� �Է����ּ���! \n" << endl;
    while (1) {

        cout << "�����ϰ� ���� ī�װ��� ��ȣ�� �Է����ּ��� :" << endl;
        display.printMainCategoriesList(main_categories);

        vector<Subcategory>& sub_categories = user_interaction.selectMainCategory(main_categories, display);
        if (sub_categories.empty())
            break;

        cout << "�����ϰ� ���� ���� ī�װ��� ��ȣ�� �Է����ּ��� :" << endl;
        display.printSubCategoriesList(sub_categories);
        Subcategory& sub_category = user_interaction.SingleSubCategory(sub_categories, display);
        if (sub_category.getSubcategoryNews().empty())
            break;

        user_interaction.receiveUserReaction(sub_category.reaction);
        cout << "���� ������� �����Դϴ�." << endl;

        display.printNewsReaction(sub_category.reaction);
        vector<News*>& select_news = sub_category.getSubcategoryNews();
        if (select_news.empty())
            break;

        cout << "���� ���� ������ ��ȣ�� �Է����ּ��� :" << endl;
        display.printNewsTitleList(select_news);

        News* one_news = user_interaction.selectNews(select_news);
        if (one_news == NULL)
            break;
        display.printNewsElements(one_news);

        user_interaction.receiveUserReaction(one_news->news_reaction);
        cout << "���� ��翡 ���� ������� �����Դϴ�." << endl;
        display.printNewsReaction(one_news->news_reaction);

        cout << "���α׷��� �����ϰ� �����ôٸ� -1�� �Է����ּ���! \n" << endl;
        cout << "ó������ ���ư��� �����ôٸ� Ű�� �Է����ּ���!" << endl;
        cin >> index_str;
        if (user_interaction.isIntegerInput(index_str))
        {
            index = stoi(index_str);
            if (index == -1)
                break;
        }

        /*
        select_news = user_interaction.selectSubCategory(sub_categories, display);
        if (select_news.empty())
            break;
        cout << "���� ���� ������ ��ȣ�� �Է����ּ��� :" << endl;
        display.printNewsTitleList(select_news);

        one_news = user_interaction.selectNews(select_news);

        if (one_news == NULL)
            break;
        cout << "************" << endl;
        display.printNewsTitle(one_news->getNewsTitle());
        cout << "************" << endl;
        display.printNewsText(one_news->getNewsText());
        cout << "************" << endl;
        display.printNewsComments(one_news->getNewsComments());
        cout << "************" << endl;

        one_news->news_reaction = user_interaction.receiveUserReaction(one_news->news_reaction);
        positive_news = one_news->news_reaction.getPositive();
        negative_news = one_news->news_reaction.getNegative();

        display.printNewsReaction(positive_news, negative_news);

        cout << "�����ϰ� �����ôٸ� -1�� �Է����ּ���!" << endl;
        cout << "ó������ ���ư��� �����ôٸ� �ƹ����ڳ� �Է����ּ���!" << endl;
        cin >> index;
        if (index == -1)
            break;
        */
    }
    cout << "���α׷��� ����Ǿ����ϴ�" << endl;

    return 0;
}

void readCsvFile(vector<News>& news, vector<string>& fwords)
{
    ifstream in("test_csv.csv"); //csv���� ���
    if (in.fail())
    {
        cout << "File not found" << endl;
        return;
    }

    int i = 0;
    while (in.good())
    {
        vector<string> row = readCsvRow(in, ',');
        vector<string> comments = listComments(row[2]);
        news.push_back(News(row[0], row[1], comments, row[3], row[4]));
        news[i++].filterSpamComment(fwords);
    }
    in.close();
}

vector<string> readCsvRow(istream& in, char delimiter)
{
    stringstream ss;
    bool inquotes = false;
    vector<string> row;//relying on RVO
    while (in.good())
    {
        char c = in.get();
        if (!inquotes && c == '"') //beginquotechar
        {
            inquotes = true;
        }
        else if (inquotes && c == '"') //quotechar
        {
            if (in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();
            }
            else //endquotechar
            {
                inquotes = false;
            }
        }
        else if (!inquotes && c == delimiter) //end of field
        {
            row.push_back(ss.str());
            ss.str("");
        }
        else if (!inquotes && (c == '\r' || c == '\n'))
        {
            if (in.peek() == '\n') { in.get(); }
            row.push_back(ss.str());
            return row;
        }
        else
        {
            ss << c;
        }
    }
}

vector<string> listComments(string comme) {
    int previous = 0;
    int start = 0;
    int end = 0;
    vector<string> comments;
    comments.clear();

    start = comme.find('\'');
    //find�� ã���� ������ npos�� ������
    while (start != string::npos) {
        end = comme.find('\'', start + 1);
        string substring = comme.substr(start + 1, end - start - 1);
        comments.push_back(substring);
        previous = end + 1;
        start = comme.find('\'', previous);
    }
    // comments.push_back(comme.substr(start, end - start));
    return comments;
}

void saveFwords(vector<string>& fwords)
{
    ifstream fword_list("fword_list.txt");
    if (fword_list.is_open())
    {
        string line;
        while (getline(fword_list, line))
        {
            fwords.push_back(line);
        }
        fword_list.close();
    }
    else
    {
        cout << "failed";
    }
    return;
}


