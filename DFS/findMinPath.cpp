#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1. 이동가능영역(사각형채우기->비우기)
// 2. DFS
int mp[101][101] = { 0, };
int answer = 987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool v[101][101] = { false, };


void DFS(int a, int b, int x, int y, int cnt)
{
    if (a == x && b == y)
    {
        answer = min(answer,cnt);
        return;
    }
    for (int i = 0;i < 4;i++)
    {
        if (a + dx[i] < 0 || a + dx[i] >= 101 || b + dy[i] < 0 || b + dy[i] >= 101)
            continue;
        if (mp[a + dx[i]][b + dy[i]] == 1 && v[a + dx[i]][b + dy[i]] == false)
        {
            v[a + dx[i]][b + dy[i]] = true;
            DFS(a + dx[i], b + dy[i], x, y, cnt+1);
            v[a + dx[i]][b + dy[i]] = false;
        }
    }

}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    // 1.1 사각형 채우기
    for (int i = 0;i < rectangle.size();i++)
    {
        // 2,2, 5,5
        int a, b, c, d;
        a = rectangle[i][0];
        b = rectangle[i][1];
        c = rectangle[i][2];
        d = rectangle[i][3];
        // (b,a) -> (d,c)
        for (int m = 2 * b;m <= 2 * d;m++)
            for (int n = 2 * a;n <= 2 * c;n++)
                mp[m][n] = 1;
    }

    // 1.2 사각형 비우기
    for (int i = 0;i < rectangle.size();i++)
    {
        int a, b, c, d;
        a = rectangle[i][0];
        b = rectangle[i][1];
        c = rectangle[i][2];
        d = rectangle[i][3];
        // (b,a) -> (d,c)
        for (int m = 2 * b + 1;m <= 2 * d - 1;m++)
            for (int n = 2 * a + 1;n <= 2 * c - 1;n++)
                mp[m][n] = 0;
    }

    //cout << characterY * 2 << "," << characterX * 2 << " -> " << itemY*2 << "," << itemX*2 << endl;

    //for (int i = 0;i < 100;i++)
    //{
    //    for (int j = 0;j < 100;j++)
    //    {
    //        cout << mp[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    // 2. DFS
    v[characterY * 2][characterX * 2] = true;
    DFS(characterY * 2, characterX * 2, itemY * 2, itemX * 2, 0);

    return answer;
}

int main()
{
    solution({ {1,1,8,4},{2,2,4,9},{3,6,9,8},{6,3,7,7},{1,1,5,7 } }, 9, 7, 6, 1);
	return 0;
}
