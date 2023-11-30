#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int>b)
{
    if (a.second > b.second)
        return true;
    else
        return false;
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    // 코스 별 주문 횟수 
    map<string, int> coursecnt;
    // STEP1 : 주문 별 가능한 조합의 수 탐색
    for (int i = 0;i < orders.size();i++)
    {
        string od = orders[i];
        // STEP 2: course 개수 별 조합 확인하기
        for (int n = 0;n < course.size();n++)
        {
            if (course[n] > od.length())
                break;
            vector<bool> tmp(od.length(), true);
            for (int k = 0;k < tmp.size() - course[n];k++)
                tmp[k] = false;
            do
            {
                string comb = "";
                for (int x = 0;x < od.length();x++)
                {
                    if (tmp[x])
                        comb += od[x];
                }
                // 알파벳순 정렬 후 
                sort(comb.begin(), comb.end());
                coursecnt[comb]++;
            } while (next_permutation(tmp.begin(), tmp.end()));
        }
    }
    // STEP3 :  갯수별 최대 값을 가지는 문자열을 출력해야함
    map<int, vector<pair<string, int>>> vp;
    for (auto iter = coursecnt.begin();iter != coursecnt.end();iter++)
    {
        if (iter->second >= 2)
            vp[iter->first.length()].push_back({iter->first, iter->second});
    }

    for (auto iter = vp.begin();iter != vp.end();iter++)
    {
        vector<pair<string, int>> v=iter->second;
        sort(v.begin(), v.end(), cmp);
        answer.push_back(v[0].first);
        int mx = v[0].second;
        for (int i = 1;i < v.size();i++)
        {
            if (v[i].second == mx)
                answer.push_back(v[i].first);
            else
                break;

        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}


int main()
{
    solution({"XYZ","XWY","WXA"},{2,3,4});
    return 0;
}
