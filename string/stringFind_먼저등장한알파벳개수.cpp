#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    answer.push_back(-1);
    for (int i = 1;i < s.length();i++)
    {
        bool isExist = false;
        for (int j = i-1;j >=0 ;j--)
        {
            if (s[j] == s[i])
            {
                answer.push_back(i-j);
                isExist = true;
                break;
            }
        }
        if (!isExist)
            answer.push_back(-1);
    }
    return answer;
}

int main_findSameChar()
{
    solution("banana");
    return 0;
}