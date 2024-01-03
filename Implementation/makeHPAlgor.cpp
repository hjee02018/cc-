// https://school.programmers.co.kr/learn/courses/30/lessons/250137
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int answer = 0;
    int mh = health;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    // 공격받지 않은 가장 앞선 시간
    int c_time = 0;

    for (int i = 0;i < attacks.size();i++)
    {
        int at = attacks[i][0];
        int d = attacks[i][1];

        // 연속성공시간 계산
        int dur = at - c_time;
        int dur_cnt = dur / t;

        if (dur > 0)
            if (dur_cnt == 0)
                health += (dur*x);
            else
                health += (dur*x+y*dur_cnt);

        // 최대 체력 준수
        if (health > mh)
            health = mh;

        // 공격 적용
        health -= d;
        c_time = at + 1;

        if (health <= 0)
            return -1;
    }

    return health;
}
