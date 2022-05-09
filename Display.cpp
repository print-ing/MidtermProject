#include "Display.h"


void Display::printMainCategoriesList(const vector<MainCategory>& main_category)
{
	for (int i = 0; i < main_category.size(); ++i)
	{
		cout << "[" << i<< "]" << main_category[i].getMainCategoryName() << "\t";
	}
	cout << endl;
}

void Display::printSubCategoriesList(const vector<Subcategory>& sub_caterory) 
{
	for (int i = 0; i < sub_caterory.size(); ++i) 
	{
		cout << "[" << i << "]" << sub_caterory[i].getSubcategoryName() << endl;
	}
}

void Display::printNewsTitleList(const vector<News*>& news_titles)
{
	for (int i = 0; i < news_titles.size(); ++i)
	{
		cout << "[" << i << "]" << news_titles[i]->getNewsTitle() << endl;
	}
}

void Display::printSelect(string name)
{
	cout << name << "을(를) 선택하셨습니다!" << endl;
}


void Display::printNewsReaction(const Reaction& reaction) 
{
	double positive = reaction.getPositive();
	double negative = reaction.getNegative();
	cout << fixed;
	cout.precision(2);
	cout << "긍정적이다. " << positive << "%" << "\t" << "부정적이다. " << negative << "%" << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
}


void Display::printNewsElements(const News* news)
{
	
	cout << "******************************************************************************************" << endl;

	cout << "\n" << news->getNewsTitle() << "\n" << endl;

	cout << "******************************************************************************************" << endl;

	for (auto iter : news->getCategory()) 
	{
		cout << iter.first << " : " << iter.second << "\t";
	}
	cout << endl;	

	cout << "******************************************************************************************" << endl;

	cout << news->getNewsText() << endl;

	cout << "******************************************************************************************" << endl;

	if (news->getNewsComments().empty())
		cout << "현재 작성된 댓글이 없습니다." << endl;
	for (int i = 0; i < news->getNewsComments().size(); i++)
		cout << "[" << i + 1 << "]" << news->getNewsComments()[i] << endl;
	
	cout << "******************************************************************************************" << endl;

}
