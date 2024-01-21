#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second>b.second)
        return true;
    else
        return false;
}
int main(int argc, char** argv)
{
    int W,N;
    int answer=0;
    cin>>W>>N;
    vector<pair<int,int>> info;
    for(int i=0;i<N;i++)
    {
        int m,p;
        cin>>m>>p;
        info.push_back({m,p});
    }
    sort(info.begin(),info.end(),cmp);
    while(W>0)
    {
        for(int i=0;i<info.size();i++)
        {
            if(info[i].first<=W)
            {
                answer += (info[i].first* info[i].second);
                W-=info[i].first;
            }
            else
            {
                answer += (W*info[i].second);
                W=0;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
