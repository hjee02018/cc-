#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 4개의 사각형으로 분할
int zero = 0;
int one = 0;
void recur(vector<vector<int>> sq, int x, int y, int n)
{
    cout << x << "," << y << " n:" << n << endl;
    if (n == 1)
    {
        if (sq[x][y] == 0)
            zero++;
        else
            one++;
        return;
    }
    int val = sq[x][y];
    bool isvalid = true;
    for (int i = x;i < x+n;i++)
    {
        if (!isvalid)
            break;
        for (int j = y;j < y+n;j++)
        {
            if (sq[i][j] != val)
            {
                recur(sq, x, y, n / 2);
                recur(sq, x + n / 2, y, n / 2);
                recur(sq, x, y + n / 2, n / 2);
                recur(sq, x + n / 2, y + n / 2, n / 2);
                isvalid = false;
                break;
            }
        }
    }
    if (sq[x][y] == 0)
        zero++;
    else if (sq[x][y] == 1)
        one++;

}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    int n = arr.size();
    recur(arr, 0, 0, n);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}

int main()
{
    solution({{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}});
    return 0;
}