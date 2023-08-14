#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int>b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    map<int, int> res;
    for (int i = 0;i < tangerine.size();i++)
        res[tangerine[i]]++;
    
    vector<pair<int, int>> vec(res.begin(), res.end());
    sort(vec.begin(), vec.end(), compare);
    
    int cnt = 0;
    for (int i = 0;i < vec.size();i++)
    {
        if (cnt >= k)
            break;
        cnt += vec[i].second;
        answer++;
    }

    return answer;
}