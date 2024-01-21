#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(pair<int,int> a, pair<int,int>b)
{
    if(a.second<b.second)
        return true;
    else if(a.second==b.second)
        if(a.first>b.first)
            return true;
        else
            return false;
    else
        return false;
}
int main(int argc, char** argv)
{
    int answer=1;
    int N;
    cin>>N;
    // 강의 시작시간, 종료시간을 담은 벡터
    vector<pair<int,int>> info;
    for(int i=0;i<N;i++)
    {
        int s,e;
        cin>>s>>e;
        info.push_back({s,e});
    }
    sort(info.begin(),info.end(),cmp);
    int cur=info[0].second;
    for(int i=1;i<info.size();i++)
    {
        if(info[i].first>=cur)
        {
            answer++;
            cur=info[i].second;
        }
    }
    cout<<answer<<endl;
    return 0;
}
