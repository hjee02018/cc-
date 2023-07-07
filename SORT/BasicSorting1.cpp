//https://school.programmers.co.kr/learn/courses/30/lessons/178871
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    // player : 현재
    // callings :해설
    // answer : 최종

    for (int i = 0;i < callings.size();i++)
    {
        string player;
        int idx = find(players.begin(), players.end(), callings[i]) - players.begin();
        player = players[idx];
        players[idx] = players[idx - 1];
        players[idx - 1] = player;
    }
    answer = players;

    return answer;
}