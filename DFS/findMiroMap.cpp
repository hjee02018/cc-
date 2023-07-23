#include <string>
#include <vector>
#include <queue>
using namespace std;

int w;
int h;
int start_x, start_y;
int end_x, end_y;
int mid_x, mid_y;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int** my_map;


void DFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    while (!q.empty())
    {
        int cur_x = q.back().first;
        int cur_y = q.back().second;
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= h || next_y >= w || next_x < 0 || next_y < 0)
                break;
            else
                q.push({next_x, next_y});

        }
    }
}

int solution(vector<string> maps) 
{
    int answer = 0;

    w = maps[0].size();
    h = maps.size();

    my_map = new int* [h];
    for (int i = 0;i < h;i++)
        my_map[i] = new int[w];

    for (int i = 0;i < h;i++)
    {
        for (int j = 0;j < w;j++)
        {
            my_map[i][j] = maps[i][j];
            if (maps[i][j] == 'S')
            {
                start_x = i;start_y = j;
            }
            if (maps[i][j] == 'E')
            {
                end_x = i;end_y = j;
            }
            if (maps[i][j] == 'L')
            {
                mid_x = i;mid_y = j;
            }
        }
    }


    // 출발 -> 레버

    // 레버 -> 도착
    
    return answer;
}