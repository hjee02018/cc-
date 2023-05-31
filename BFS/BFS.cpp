#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[26][26];
int visited[26][26]{ 0, };
int N;

int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };

int BFS(int i, int j)
{
	int count = 1;
	queue<pair<int, int>> qu;
	// -1 : visited
	visited[i][j] = -1;
	qu.push({i,j});
	while (!qu.empty())
	{
		int cur_x = qu.front().first;
		int cur_y = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = nx[i] + cur_x;
			int next_y = ny[i] + cur_y;
			//cout << next_x << ";" << next_y << endl;
			if (next_x >= N || next_y >= N || next_x < 0 || next_y<0)
				continue;
			if (map[next_x][next_y] == 0)
				continue;
			if (visited[next_x][next_y] == -1)
				continue;
			else
			{
				visited[next_x][next_y] = -1;
				qu.push({ next_x, next_y });
				count++;
			}
		}
	}
	return count;
}

int main7(int argc, char** argv)
{
	cin >> N;
	vector<int>answer;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%1d", &map[i][j]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1&&visited[i][j]!=-1)
			{
				// Å½»ö
				int cnt = BFS(i,j);
				answer.push_back(cnt);
			}
		}
	}
	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());
	std::vector<int>::iterator iter;
	for (iter = answer.begin(); iter != answer.end(); iter++)
	{
		cout<< *iter << endl;
	}
	return 0;
}