//https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "Yes";
    int idx1=0, idx2=0;
    for (int i = 0;i < goal.size();i++)
    {
        string word = goal[i];
        if (cards1[idx1] == word)
        {
            idx1++;
            continue;
        }
        else if (cards2[idx2] == word)
        {
            idx2++;
            continue;
        }
        else
        {
            answer = "No";
            break;
        }
    }
    cout << answer << endl;
    return answer;
}

int main1()
{
    solution({ "i", "drink", "water" }, { "want", "to" }, { "i", "want", "to", "drink", "water" });
    return 0;
}