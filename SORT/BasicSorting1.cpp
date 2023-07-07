//https://school.programmers.co.kr/learn/courses/30/lessons/178871
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
player: 현재
callings : 해설
answer : 최종
*/


// 시간 초과 개선을 위한 수정 사항 : map
vector<string> solution1(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    map<string, int> playerMap;
    for (int i=0;i < players.size();i++)
        playerMap[players[i]] = i;
    for (int i = 0;i < callings.size();i++)
    {
        int idx = playerMap[callings[i]];
        playerMap[players[idx]] = idx - 1;
        playerMap[players[idx - 1]] = idx;

        swap(players[idx], players[idx - 1]);
    }

    answer = players;
    return answer;
}

vector<string> solution2(vector<string> players, vector<string> callings)
{
    vector<string> answer;

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