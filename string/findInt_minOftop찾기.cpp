#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    vector<int> top;
    vector<int> min_of_top ;
    int min =2001;
    for (int i = 0;i < k;i++)
    {
        if (i > score.size())
        {
            break;
        }
        top.push_back(score[i]);
        if (score[i] < min)
            min = score[i];
        min_of_top.push_back(min);
    }

    sort(top.begin(), top.end(),greater<>());
    for (int i = k;i < score.size();i++)
    {
        if (top.back() < score[i])
        {
            top.pop_back();
            top.push_back(score[i]);
        }
        sort(top.begin(), top.end(), greater<>());
        min_of_top.push_back(top.back());
    }


    answer = min_of_top;

    return answer;
}

int main_minofTop()
{
    solution(9, {10,30,40,3,0,20,4});
    return 0;
}