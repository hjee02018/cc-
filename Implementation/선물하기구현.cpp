// https://school.programmers.co.kr/learn/courses/30/lessons/258712
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
// 선물 기록 -> 더 많이 준 사람+1
// 선물 기록 동일 or x -> 선물 지수 기준
// 지수가 같다면 pass
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;
    // {a,b} , 5 : a->b : 5개
    map<pair<string, string>, int> gList;
    // 이름, 선물지수
    map<string, int> gRate;
    // 이름, 다음달에 받을 개수
    map<string, int>gNext;

    for (int i = 0;i < gifts.size();i++)
    {
        string log = gifts[i];
        string give = log.substr(0, log.find(' '));
        string recv = log.substr(log.find(' ')+1);
        gList[{give, recv}]++;
        gRate[give]++;
        gRate[recv]--;
    }
    for (int i = 0;i < friends.size() - 1;i++)
    {
        // p1과 p2간의 비교
        for (int j = i + 1;j < friends.size();j++)
        {
            string p1 = friends[i];
            string p2 = friends[j];
            // a=p1->p2
            // b=p2->p1
            int a = gList[{p1, p2}];
            int b = gList[{p2, p1}];
            if (a > b)
                gNext[p1]++;
            else if (a < b)
                gNext[p2]++;
            else
                // 선물지수도 같다면? 
                if (gRate[p1] > gRate[p2])
                    gNext[p1]++;
                else if (gRate[p1] < gRate[p2])
                    gNext[p2]++;
                else
                    continue;
        }
    }
    for (auto iter = gNext.begin();iter != gNext.end();iter++)
    {
        if (iter->second > answer)
            answer = iter->second;
    }

    return answer;
}
