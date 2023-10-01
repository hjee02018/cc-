#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int ans1[5] = { 1,2,3,4,5 };
int ans2[8] = { 2,1,2,3,2,4,2,5 };
int ans3[10] = { 3,3,1,1,2,2,4,4,5,5};
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else if (a.second > b.second)
        return true;
    else
        return false;
}
vector<int> solution(vector < int > answers)
{
    vector<int> answer;
    // 유형(사람)/정답수
    map<int, int>score;
    score[1] = 0;
    score[2] = 0;
    score[3] = 0;
    for (int i = 0;i < answers.size();i++)
    {
        int ans = answers[i];
        if (ans1[i % 5] == ans)
            score[1]++;
        if (ans2[i % 8] == ans)
            score[2]++;
        if (ans3[i % 10] == ans)
            score[3]++;
    }
    vector<pair<int, int>> vec(score.begin(), score.end());
    sort(vec.begin(), vec.end(), cmp);
    if (vec[0].second == vec[1].second)
    {
        if (vec[1].second == vec[2].second)
        {
            answer.push_back(vec[0].first);
            answer.push_back(vec[1].first);
            answer.push_back(vec[2].first);
        }
        else
        {
            answer.push_back(vec[0].first);
            answer.push_back(vec[1].first);
        }
    }
    else
        answer.push_back(vec[0].first);

    return answer;
}

int main()
{
    solution({ 5,5,5,5,5,5,5,5 });
    return 0;
}