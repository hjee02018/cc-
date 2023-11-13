#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 부분 수열의 최대합
long long find_max(vector<int> v)
{
    vector<long long> dp(v.size());
    dp[0]=v[0];
    for(int i=1;i<dp.size();i++)
        dp[i]=max(1LL*v[i],dp[i-1]+v[i]);
    long long res = *max_element(dp.begin(),dp.end());
    return res;
}

long long solution(vector<int> sequence) 
{
    long long answer = 0;
    vector<int> s1,s2;
    int a,b;
    a=1;
    b=-1;
    for(int i=0;i<sequence.size();i++)
    {
        s1.push_back(sequence[i]*a);
        a*=-1;
        s2.push_back(sequence[i]*b);
        b*=-1;
    }
    return max(find_max(s1),find_max(s2));
}
