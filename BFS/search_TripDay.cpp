#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;
bool visited[100][100];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(vector<string> maps, int k,int j)
{
	queue<pair<int, int>> q;
	q.push({ k,j });
	visited[k][j] = true;

	int result = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		result += (maps[x][y] - '0');
		q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[k].size())
				continue;
			if (maps[nx][ny] != 'X'&&visited[nx][ny]==false)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	answer.push_back(result);
}

vector<int>solution(vector<string> maps)
{
	for (int i = 0;i < maps.size();i++)
		for (int j = 0;j < maps[i].size();j++)
			if (maps[i][j] != 'X' && !visited[i][j])
				bfs(maps, i, j);

	sort(answer.begin(), answer.end());
	
	if (answer.size() == 0)
		answer.push_back(-1);
	

	return answer;
}

int main()
{
	solution({ "X591X","X1X5X","X231X", "1XXX1" });
	return 0;
}