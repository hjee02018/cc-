#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N;
vector<vector<int>> dp;

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    N= triangle.size();
    vector<int> v1;
    v1.push_back(triangle[0][0]);
    dp.push_back(v1);
    // top-down
    for(int i=1;i<N;i++)
    {
        vector<int> tmp;
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                tmp.push_back(dp[i-1][j]+triangle[i][j]);
            else if(j==i)
                tmp.push_back(dp[i-1][j-1]+triangle[i][j]);
            else
                tmp.push_back(max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]);
        }
        dp.push_back(tmp);
    }
    for(int i=0;i<N;i++)
    {
        if(dp[N-1][i]>answer)
            answer=dp[N-1][i];
    }
    return answer;
}
