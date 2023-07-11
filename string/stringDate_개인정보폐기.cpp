// https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string getExp(vector<string>terms, string type)
{
    for (int i = 0;i < terms.size();i++)
    {
        if (terms[i].substr(0, terms[i].find(" ")) == type)
            return terms[i].substr(terms[i].find(" ") + 1, terms[i].length());
    }
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;
    int idx = today.find(".");
    int today_year = stoi( today.substr(0,idx));
    idx = idx + 1;
    int idx2 = today.find( ".",idx);
    int today_month =stoi(today.substr(idx,idx2));
    idx2 = idx2 + 1;
    int today_day = stoi(today.substr(idx2,today.length()));

    for (int i = 0;i < privacies.size();i++)
    {
        string dates;
        string type;
        dates = privacies[i].substr(0,privacies[i].find(" "));
        type = privacies[i].substr(privacies[i].find(" ")+1, privacies[i].length());
        int term = stoi( getExp(terms,type));

        
        size_t pos = dates.find(".");
        int year = stoi( dates.substr(0, pos));

        size_t startPos = pos + 1;
        pos = dates.find(".", startPos);
        int month= stoi(dates.substr(startPos, pos - startPos));

        int day = stoi(dates.substr(pos + 1));

        
        // 기간 더하기
        month += term%12;
        year += term / 12;
        if (month > 12)
        {
            year += 1;
            month -= 12;
        }
        
        cout << today_year << "." << today_month << "." << today_day << endl;
        
        // 파기해야할 년,월,일
        cout << year << "." << month << "." << day << endl;

        // 오늘 날짜와 비교
        if (today_year > year)
            answer.push_back(i+1);
        else if (today_year == year)
        {
            if (today_month > month)
                answer.push_back(i+1);
            else if (today_month == month)
            {
                if (today_day >= day)
                    answer.push_back(i+1);
            }
        }
    }
    
    
    return answer;
}

int main()
{
    solution("2022.05.19", { "A 6", "B 12", "C 3" },{ "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
    return 0;
}