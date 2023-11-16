//https://school.programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
/*
최다 재생 장르 순
최다 재생 음악 순
고유 번호 순
*/
bool cmp1(pair<string,int> a, pair<string, int>b)
{
    return a.second>b.second;
}
bool cmp2(pair<int,int> a, pair<int,int> b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    map<string,int> gp;
    // 1. 장르순
    for(int i=0;i<genres.size();i++)
        gp[genres[i]]+= plays[i];
    vector<pair<string,int>> gv(gp.begin(),gp.end());
    sort(gv.begin(),gv.end(),cmp1);
   
    // 2. 재생순
    for(int i=0;i<gv.size();i++)
    {
        string gen=gv[i].first;
        // 고유 번호, 재생횟수
        vector<pair<int,int>> play;
        for(int i=0;i<genres.size();i++)
            if(genres[i]==gen)
                play.push_back({i,plays[i]});
        
        sort(play.begin(),play.end(),cmp2);
        int m;
        if(2<play.size())
            m=2;
        else
            m=play.size();
        for(int i=0;i<m;i++)
            answer.push_back(play[i].first);
    }
    
    return answer;
}
