/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include "Reaction.h"
#include "News.h"
#include "Category.h"
using namespace std;

void readCsvFile(News* news);
vector<string> listComments(string comment);
vector<string> readCsvRow(istream& in, char delimiter);
// ?
vector<string> readCsvRow(string& in, char delimiter);


int main()
{
    News news[10];
    for (int i = 0; i < 10; i++) news[i] = News();
    readCsvFile(news);
    //테스트 코드 기사 제목, 본문, 댓글 확인 용
    
    cout <<"1번째 뉴스 제목 :\n" << news[0].getNewsTitle() << endl;
    cout << "1번째 뉴스 본문 :\n" << news[0].getNewsText() << endl;
    cout<< "1번째 뉴스 댓글"<< endl;
    for (int i = 0;i< news[0].getNewsComments().size();i++)
        cout <<"[" << i + 1 << "]" << news[0].getNewsComments()[i] << endl;
    return 0;
}


void readCsvFile(News* news)
{
    ifstream in("test_csv.csv"); //csv파일 경로
    if (in.fail())
    {
        cout << "File not found" << endl;
        return;
    }
    while (in.good())
    {
        for (int i = 0; i < 10; i++) {
            vector<string> row = readCsvRow(in, ',');
            //row[0] : 기사 제목, row[1] : 기사 본문
            vector<string> comments = listComments(row[2]);
            news[i].setNews(row[0], row[1], comments, row[3], row[4]);
        }
    }
    in.close();
}

vector<string> readCsvRow(string& line, char delimiter)
{
    stringstream ss(line);
    return readCsvRow(ss, delimiter);
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
    //find는 찾을게 없으면 npos를 리턴함
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
*/