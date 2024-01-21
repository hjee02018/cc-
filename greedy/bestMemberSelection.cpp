#include<iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char** argv)
{
    int N,M;
    cin>>N>>M;
    vector<int> w;
    // 회원i, 최고라 생각하는지
    map<int,bool>isbest;
    vector<pair<int,int>> f;
    for(int i=0;i<N;i++)
    {
        int weight;
        cin>>weight;
        w.push_back(weight);
        isbest[i+1]=true;
    }
    
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        if(w[a-1]<w[b-1])
            isbest[a]=false;
        else if(w[b-1]<w[a-1])
            isbest[b]=false;
        else
        {
            isbest[a]=false;
            isbest[b]=false;
        }
        f.push_back({a,b});
    }
    int answer=0;
    for(auto iter=isbest.begin();iter!=isbest.end();iter++)
    {
        if(iter->second==true)
            answer++;
    }
    cout<<answer<<endl;
    return 0;
}
// 7 5 7 7 1
// 1 true 
// 2 false
// 3 false
// 4 false
// 5 true
