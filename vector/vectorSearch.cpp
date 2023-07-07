#include <string>
#include <vector>
#include <iostream>

using namespace std;

int w, h;
int** map;

bool isValid(int x,int y)
{
    // op방향 n이동 시
    /*
    * i- 중간에 장애물(X, 40)
    * ii- x >=h or y>=w (맵을 벗어나는지)
    */

    if (x >= h || x < 0)
        return false;
    if (y >= w || y < 0)
        return false;
    if (map[x][y] == 40)
        return false;
    return true;
}



vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    //열
    w = park[0].size();
    //행
    h = park.size();
    int start_x, start_y;
    map = new int* [h];
    for (int i = 0; i < h; i++)
    {
        map[i] = new int[w];
        for (int j = 0; j < w; j++)
        {
            map[i][j] = park[i][j] - '0';
            if (map[i][j] == 35)
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    /*
    * S:35
    * O:31
    * X:40
    */
    //for (int i = 0; i < h; i++)
    //    for (int j = 0; j < w; j++)
    //        cout << i << "행" << j << "열 : " << map[i][j]<<endl;
    //    cout << endl;
    int cur_x = start_x;
    int cur_y = start_y;
    //cout << start_x << "행" << start_y << "열" << endl;
    for (int i = 0;i < routes.size();i++)
    {
        char op = routes[i][0];
        int n = routes[i][2]-'0';
        bool Valid = true;
        switch (op)
        {
        case 'N':
            Valid = true;
            for (int k = 0;k < n;k++)
            {
                if (isValid(cur_x -( k+1), cur_y) == false)
                {
                    Valid = false;
                    break;
                }
            }
            if (Valid)
                cur_x = cur_x - n;
            break;
        case 'S':
            Valid = true;
            for (int k = 0;k < n;k++)
            {
                if (isValid(cur_x + (k+1), cur_y) == false)
                {
                    Valid = false;
                    break;
                }
            }
            if (Valid)
                cur_x = cur_x + n;
            break;
        case 'W':
            Valid = true;
            for (int k = 0;k < n;k++)
            {
                if (isValid(cur_x, cur_y-(k+1)) == false)
                {
                    Valid = false;
                    break;
                }
            }
            if (Valid)
                cur_y = cur_y - n;
            break;
        case 'E':
            Valid = true;
            for (int k = 0;k < n;k++)
            {
                if (isValid(cur_x , cur_y+(k+1)) == false)
                {
                    Valid = false;
                    break;
                }
            }
            if (Valid)
                cur_y = cur_y + n;
            break;
        default:
            break;
        }
        cout << cur_x << "," << cur_y << endl;
    }

    cout << cur_x << cur_y << endl;
    answer.push_back(cur_x);
    answer.push_back(cur_y);

    for (int i = 0; i < w; i++) {
        delete[] map[i];
    }
    delete[] map;

    return answer;
}

int main()
{
    solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 2","W 1" });
    return 0;
}