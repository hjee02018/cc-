#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> food) 
{
    string answer = "";
 
    int idx = 0;
    for (int i = 0;i < food.size();i++)
    {
        // i번째 음식의 개수 : cnt개
        int cnt = food[i];
        int no = cnt / 2;
        if (no == 0)
            continue;
        else
        {
            for (int j = 0;j < no;j++)
                answer += to_string( i);
        }
    }
    answer += to_string(0);
    int len = answer.length() - 1;

    for (int i = len-1;i >=0;i--)
        answer += (answer[i]);


    return answer;
}


int main_stringArray()
{
    solution({1,7,1,2});
    return 0;
}