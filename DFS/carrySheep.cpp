#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
* 양의 수<= 늑대 : 잡아먹힘
* 가능한 많은 양을 모아서 루트로 돌아오기
*/

int N,ans;
int sheep=1, wolf=0;
vector<int> adj[17];
vector<int> infos;

void DFS(int n)
{
    int s = adj[n].size();
    for (int i = 0;i < s;i++)
    {
        int next_n = adj[n].back();
        adj[n].pop_back();

        if (infos[next_n] == 0)
        {
            sheep++;
            DFS(next_n);
        }
        else
        {
            if (sheep > wolf + 1)
                DFS(next_n);
            else
                continue;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    int answer = 1;
    N = info.size();
    infos = info;

    for (int i = 0;i < edges.size();i++)
        adj[edges[i].front()].push_back(edges[i].back());
    
    DFS(0);
    answer = sheep;
    cout << answer << endl;
    return answer;
}

int main()
{
    solution({ 0,0,1,1,1,0,1,0,1,0,1,1 }, { {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9} });
    return 0;
}