// https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>
#include <queue>
using namespace std;

int mp[100][100];
int answer = 0;

// n행m열
void bfs(int x, int y,int m,int n)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    int cnt = 0;
    while (!q.empty())
    {
        cnt++;
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        if (nx == n-1 && ny == m-1)
        {
            answer++;
            continue;
        }
        // 아래로
        if (nx + 1<n)
            if(mp[nx+1][ny]!=-1)
                q.push({ nx + 1,ny });
        // 오른쪽으로
        if (ny + 1 <m)
            if (mp[nx][ny + 1] != -1)
                q.push({ nx,ny + 1 });

    }
}

int solution_bfs(int m, int n, vector<vector<int>> puddles) 
{
    for (int i = 0;i < puddles.size();i++)
        mp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    bfs(0, 0,m,n);
    return answer;
}

int dp[100][100];
// n행 m열
// 점화식 : dp[i][j] = dp[i-1][j] + dp[i][j-1]
int solution_dp(int m,int n,vector<vector<int>>puddles)
{
    dp[0][0] = 1;
    for (int i = 0;i < puddles.size();i++)
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            int a = 0;
            int b = 0;
            if (dp[i][j] == -1)
                continue;
            if (dp[i - 1][j] != -1)
                a = dp[i - 1][j];
            if (dp[i][j - 1] != -1)
                b = dp[i][j - 1];
            dp[i][j] += a + b;
        }
    }
    return dp[n - 1][m - 1];
}


int main()
{
    solution_bfs(4, 3, { {2,2} });
    solution_dp(4, 3, {{2,2}});
    return 0;
}