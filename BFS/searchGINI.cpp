#include <iostream>
#include <vector>
using namespace std;

// input map
char map[50][50];
// if already visited
bool isVisit[50][50];
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

int R, C;

void Spread()
{
	bool isVisitied[50][50] = { false, };
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '*')
			{
				for (int k = 0; k < 4; k++)
				{
					int next_x = i + dx[k];
					int next_y = j + dy[k];
					if (map[next_x][next_y] == 'W'||map[next_x][next_y]=='*' || map[next_x][next_y] == 'H' || map[next_x][next_y] == 'X')
						continue;
					if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
						continue;
					if (isVisitied[next_x][next_y] == true)
						continue;
					else
					{
						isVisitied[next_x][next_y] = true;
						map[next_x][next_y] = '*';
					}
				}
			}
		}
	}
}

int main()
{
	int start_x, start_y;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'W')
			{
				start_x = i;
				start_y = j;
				isVisit[i][j] = true;
			}
		}
	}
	bool isSuccess = false;
	int cnt = 0;
	vector<pair<int, int>> res;
	res.push_back({ start_x, start_y });
	while (!res.empty())
	{
		Spread();
		int current_x = res.back().first;
		int current_y = res.back().second;
		res.pop_back();
		for (int k = 0; k < 4; k++)
		{
			int next_x = current_x + dx[k];
			int next_y = current_y + dy[k];

			if (next_x < 0 || next_y < 0 || next_x >= R || next_y >= C)
				continue;
			if (map[next_x][next_y] == 'H')
			{
				isSuccess = true;
				cnt++;
				cout << cnt << endl;
				return 0;
			}
			if (isVisit[next_x][next_y] == true)
				continue;
			if (map[next_x][next_y] == 'W' || map[next_x][next_y] == '*' || map[next_x][next_y] == 'X')
				continue;
			else
			{
				isVisit[next_x][next_y] = true;
				res.push_back({ next_x,next_y });
			}
		}
		cnt++;
	}
	if (!isSuccess)
		cout << "FAIL" << endl;
	return 0;
}