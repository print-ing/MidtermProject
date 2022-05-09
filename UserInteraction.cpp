#include "UserInteraction.h"

void UserInteraction::receiveUserReaction(Reaction& reaction)
{
    string index_str;
    cout << "긍정적으로 생각하신다면 [1]" << "\t" << "부정적으로 생각하신다면 [2]" << endl;
    cout << "반응하고 싶지 않으시다면 다른 숫자를 입력해주세요. " << endl;
    while (1)
    {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            switch (index) {
            case 1:
                reaction.PlusPositive();
                cout << "긍정적인 반응을 입력하셨습니다." << endl;
                break;
            case 2:
                reaction.PlusNegative();
                cout << "부정적인 반응을 입력하셨습니다." << endl;
                break;
            default:
                cout << "반응을 입력하지 않으셨습니다." << endl;
            }
            cout << "------------------------------------------------------------------------------------------" << endl;
            return;
        }
        else
        {
            cout << "잘못된 입력입니다!!!!" << endl;
        }
    }
}

vector<Subcategory>& UserInteraction::selectMainCategory(vector<MainCategory>& main_category, Display display)
{
    vector<Subcategory> empty_subcategories;
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "기사 분류 선택을 그만두셨습니다." << endl;
                return empty_subcategories;
            }
            else if (index >= main_category.size()) 
            {
                cout << "잘못된 입력입니다!!!!" << endl;
            }
            else 
            {
                display.printSelect(main_category[index].getMainCategoryName());
                return main_category[index].getSubcategories();
            }
        }
        else
        {
            cout << "잘못된 입력입니다!!!!" << endl;
        }
    }
}

Subcategory& UserInteraction::SingleSubCategory(vector<Subcategory>& sub_category, Display display)
{
    Subcategory empty_subcategory;
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "기사 분류 선택을 그만두셨습니다." << endl;
                return empty_subcategory;
            }
            else if (index >= sub_category.size()) {
                cout << "잘못된 입력입니다!!!!" << endl;
            }
            else {
                display.printSelect(sub_category[index].getSubcategoryName());
                return sub_category[index];
            }
        }
        else
        {
            cout << "잘못된 입력입니다!!!!" << endl;
        }
    }
}

/*
vector<News*> UserInteraction::selectSubCategory(vector<Subcategory> sub_category, Display display)
{
    cout << "종료하고 싶으시다면 -1을 입력해주세요!" << endl;
    vector<News*> select_news;
    int index;
    while (1) {
        cin >> index;

        if (index == -1)
        {
            cout << "기사 분류 선택을 그만두셨습니다." << endl;
            return select_news;
        }
        else if (index >= sub_category.size()) {
            cout << "잘못된 입력입니다!!!!" << endl;
        }

        else {
            display.printSelect(sub_category[index].getSubcategoryName());
            return sub_category[index].getSubcategoryNews();
        }
    }
}
*/

News* UserInteraction::selectNews(const vector<News*>& selected_news)
{
    string index_str;
    while (1) {
        cin >> index_str;
        bool is_integer = isIntegerInput(index_str);
        if (is_integer)
        {
            int index = stoi(index_str);
            if (index == -1)
            {
                cout << "기사 선택을 그만두셨습니다." << endl;
                return NULL;
            }
            else if (index >= selected_news.size()) {
                cout << "잘못된 입력입니다!!!!" << endl;
            }

            else 
            {
                cout << "[" << index << "]" << "번 뉴스를 선택하셨습니다!" << endl;
                return selected_news[index];
            }
        }
        else
        {
            cout << "잘못된 입력입니다!!!!" << endl;
        }
    }
}

bool UserInteraction::isIntegerInput(string input)
{
    bool is_integer = 0;
    if (input.size() >= 10)
    {
        return 0;
    }
    for (int i = 0; i < input.size(); ++i)
    {
        if ('0' <= input[i] && '9' >= input[i])
        {
            is_integer = 1;
            break;
        }
    }
    return is_integer;
}