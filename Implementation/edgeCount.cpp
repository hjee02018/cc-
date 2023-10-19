// https://school.programmers.co.kr/learn/courses/30/lessons/49994
#include <string>
#include <map>
using namespace std;

int solution(string dirs)
{
    int answer = 0;
    int cx = 0, cy = 0;
    map<pair<pair<int, int>, pair<int, int>>, int>mp;
    for (int i = 0;i < dirs.length();i++)
    {
        char d = dirs[i];
        int nx, ny;
        if (d == 'L')
        {
            if (cx - 1 < -5)
                continue;
            nx = cx - 1;
            ny = cy;
        }
        else if (d == 'R')
        {
            if (cx + 1 > 5)
                continue;
            nx = cx + 1;
            ny = cy;
        }
        else if (d == 'U')
        {
            if (cy + 1 > 5)
                continue;
            ny = cy + 1;
            nx = cx;
        }
        else
        {
            if (cy - 1 < -5)
                continue;
            ny = cy - 1;
            nx = cx;
        }
        // (cx,cy) -> (nx,cy)
        // {(2,2),(1,1)} 이미 있다면 -> 
        if (mp[{ {nx, ny}, { cx,cy }}] > 0)
            mp[{ {nx, ny}, { cx,cy }}]++;
        else
            mp[{ {cx, cy}, { nx,ny }}]++;

        cx = nx;
        cy = ny;
    }

    answer = mp.size() / 2;
    return answer;
}