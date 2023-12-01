#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
// 한번에 한명 신고, 여러명 신고 가능
// k번 이상 신고 -> 정지 & 신고한 유저에게 메일 발송
vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    // id별 신고한 유저
    map<string, vector<string>> user_report;
    // 유저별 신고 횟수
    map<string, int> report_list;
    // 정지당한 유저
    vector<string> stop;
    // 1. 유저별 신고 횟수(report_list)와 유저별 신고 대상(user_report)
    for (int i = 0;i < report.size();i++)
    {
        string r = report[i];
        string a, b;
        a = r.substr(0, r.find(' '));
        b = r.substr(r.find(' '));
        // 동일인 여러번 신고 무시해야함.
        if (find(user_report[a].begin(),user_report[a].end(),b) == user_report[a].end())
        {
            user_report[a].push_back(b);
            report_list[b]++;
        }
    }

    // 2. k번 이상 신고 -> stop
    for (auto iter = report_list.begin();iter != report_list.end();iter++)
        if (iter->second >= k)
            stop.push_back(iter->first);

    // 3. user_report 중 stop이 몇명있는지
    for(int i=0;i<id_list.size();i++)
    {
        string u=id_list[i];
        vector<string> rp = user_report[u];
        int ans=0;
        // rp중 stop에 포함된 사람이 몇명있는지
        for(int i=0;i<stop.size();i++)
            if(find(rp.begin(),rp.end(),stop[i])!=rp.end())
                ans++;
        answer.push_back(ans);
    }

    return answer;
}
