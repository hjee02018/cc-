// https://school.programmers.co.kr/learn/courses/30/lessons/68645
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>>mp(n + 1, vector<int>(n + 1));
    // cnt : 총 숫자의 개수
    int cnt = ((n + 1) * n) / 2;
    int type = 1;
    int tmp = n;
    int line = 1;
    int row = 0;
    map<int, vector<int>>t;
    int no = 1;
    for (int i = 0;i < n;i++)
        mp[i + 1] = vector<int>(i + 1);
    while (no <= cnt)
    {
        if (type == 1)
        {
            for (int k = 0;k < tmp;k++)
                mp[line++][row] = no++;
            type = 2;
            line--;
        }
        else if (type == 2)
        {
            for (int k = 0;k < tmp;k++)
                mp[line][++row] = no++;
            type = 3;
            line--;
        }
        else
        {
            for (int k = 0;k < tmp;k++)
                mp[line--][--row] = no++;
            type = 1;
            line += 2;
        }
        tmp--;
    }
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < mp[i].size();j++)
            answer.push_back(mp[i][j]);

    return answer;
}
