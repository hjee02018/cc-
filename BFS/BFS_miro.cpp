#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> graph;
int start_x, start_y;
int mid_x, mid_y;
int end_x, end_y;
int w, h;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int DFS(vector<int>start, vector<int>end)
{
    int endx = end[0];
    int endy = end[1];
    bool isValid = false;
    queue<vector<int>> q;
    q.push(start);
    while (!q.empty())
    {
        vector<int>tmp = q.front(); q.pop();
        int cur_x = tmp[0];
        int cur_y = tmp[1];

        for (int i = 0;i < 4;i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_x == endx && next_y == endy)
            {
                isValid = true;
                break;
            }
            else if (next_x<0||next_y<0|| next_x >= h || next_y >= w || graph[next_x][next_y] == 'X')
                continue;
            else
            {
                q.push({ next_x,next_y });
            }
        }
    }
    if (isValid)
    {
        return q.size();
    }
    else
        return -1;
}

int BFS(vector<int> start, vector<int>end)
{
    bool isVisited[100][100] = { false, };
    int endx, endy;
    endx = end[0];
    endy = end[1];

    queue<vector<int>> q;
    q.push(start);
    int moves = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0;i < levelSize;i++)
        {
            int cur_x = q.front()[0];
            int cur_y = q.front()[1];
            q.pop();

            if (cur_x == endx && cur_y == endy)
            {
                return moves;
            }
            for (int j = 0;j < 4;j++)
            {
                int next_x = cur_x + dx[j];
                int next_y = cur_y + dy[j];
                if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w || isVisited[next_x][next_y] == true)
                    continue;
                else if (graph[next_x][next_y] == 'X')
                    continue;
                else
                {
                    q.push({ next_x,next_y });
                    isVisited[next_x][next_y] = true;
                }
            }
        }
        moves++;
    }
    return -1;
}

int solution(vector<string> maps)
{
    int answer = 0;
    w = maps[0].size();
    h = maps.size();
    for (int i = 0;i < h;i++)
    {
        string tmp = maps[i];
        vector<int> line;
        graph.push_back(line);
        for (int j = 0;j < w;j++)
        {
            if (tmp[j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            if (tmp[j] == 'E')
            {
                end_x = i;
                end_y = j;
            }
            if (tmp[j] == 'L')
            {
                mid_x = i;
                mid_y = j;
            }
            graph[i].push_back(tmp[j]);
        }
    }
    int ret1 = BFS({ start_x,start_y }, { mid_x,mid_y });
    if (ret1 != -1)
    {
        int ret2 = BFS({ mid_x,mid_y }, { end_x,end_y });
        if (ret2 != -1)
            return ret1 + ret2;
        else
            return -1;
    }
    else
        return -1;
}

int main()
{
    solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
    return 0;
}