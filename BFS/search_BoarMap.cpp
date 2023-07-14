#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int solution(vector<string> board) 
{
    int answer = 0;
    // h«‡ wø≠
    int w = board[0].size();
    int h = board.size();

    queue<pair<int, int>>q;
    int visited[100][100];
    memset(visited, -1, sizeof(visited));
    for (int i = 0;i < h;i++)
        for (int j = 0;j < w;j++)
            if (board[i][j] == 'R')
                q.push({ i,j });
    visited[q.front().first][q.front().second] = 0;

    while (!q.empty())
    {
        pair<int, int>cur = q.front();
        q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first, ny = cur.second;
            while (1)
            {
                if (nx<0 || ny<0 || nx>=h || ny>=w)
                    break;
                if (board[nx][ny] == 'D')
                    break;
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            if (board[nx][ny] == 'G')
                return visited[cur.first][cur.second] + 1;
            if (visited[nx][ny] >= 0)
                continue;

            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            q.push({ nx,ny });

        }
    }
    return (-1);

    //return answer;
}

int main()
{
    int res = solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });
    cout << res << endl;
    return 0;
}