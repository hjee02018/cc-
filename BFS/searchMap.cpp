

#include<iostream>
#include <queue>
using namespace std;
//https://softeer.ai/practice/info.do?idx=1&eid=583

int R, C;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
// input map
char map[50][50];
// rain map
vector<pair<int, int>> rain;
bool isVisited[50][50] = {false,};

// 모든 *를 찾아서 상하좌우로 *표시(which is not X,W,H , no checked(-1))
// if is checked > 이번에 확산된 소나기 이므로 -1로 설정하여 더이상 그 위치로부터 재확산 되지 않도록
void Spread()
{
	bool isChecked[50][50] = { false, };
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '*' && isChecked[i][j] ==false)
			{
				//cout << i << "행" << j << "열"<<endl;
				for (int k = 0; k < 4; k++)
				{
					int next_x = dx[k] + i;
					int next_y = dy[k] + j;
					if (next_x >= R || next_y >= C || next_x < 0 || next_y < 0)
						continue;
					if (map[next_x][next_y] == 'X' || map[next_x][next_y] == 'H' || map[next_x][next_y] == 'W')
						continue;
					if (map[next_x][next_y] == '*')
						continue;
					else
					{
						isChecked[next_x][next_y] = true;
						map[next_x][next_y] = '*';
						//cout << next_x << "행" << next_y << "열 확산" << endl;
					}
				}
			}
		}
	}
}

int BFS(int a, int b)
{
	bool isChecked[50][50] = { false, };

	for (int i = 0; i < rain.size(); i++)
	{
		for (int k = 0; k < 4; k++)
		{
			int next_x = dx[k] + i;
			int next_y = dy[k] + j;
			if (next_x >= R || next_y >= C || next_x < 0 || next_y < 0)
				continue;
			if (map[next_x][next_y] == 'X' || map[next_x][next_y] == 'H' || map[next_x][next_y] == 'W')
				continue;
			if (map[next_x][next_y] == '*')
				continue;
			else
			{
				isChecked[next_x][next_y] = true;
				map[next_x][next_y] = '*';
				//cout << next_x << "행" << next_y << "열 확산" << endl;
			}
		}
	}

	bool isSuccess = false;
	int res = 0;
	queue<pair<int, int>> ret;

	ret.push({ a,b });

	while (!ret.empty())
	{
		// 소나기 확산 먼저 체크
		int cur_x = ret.front().first;
		int cur_y = ret.front().second;
		ret.pop();
		Spread();
		for (int i = 0; i < 4; i++)
		{
			int next_x = dx[i] + cur_x;
			int next_y = dy[i] + cur_y;
			if (next_x >= R || next_y >= C || next_x < 0 || next_y < 0)
				continue;
			if (isVisited[next_x][next_y] == true)
				continue;
			if (map[next_x][next_y] == '*' || map[next_x][next_y] == 'X' || map[next_x][next_y] == 'W')
				continue;
			// H에 도착
			if (map[next_x][next_y] == 'H')
			{
				res++;
				isSuccess = true;
				return res;
			}
			else
			{
				isVisited[next_x][next_y] = true;
				ret.push({ next_x,next_y });
			}
		}
		res++;
	}

	// FAIL...
	if (isSuccess == false)
		return -1;
}

int main(int argc, char** argv)
{
	int res = 0;
	
	int a, b;

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	// 매분마다 상,하,좌,우 & 소나기는 매분마다 상,하,좌,우 확산
	// 소나기와 강은 지날 수 X
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'W')
			{
				a = i;
				b = j;
				isVisited[i][j] = true;
			}
			else if (map[i][j] == '*')
			{
				rain.push_back({ i,j });
			}
		}
	}

	res = BFS(a, b);
	if (res == -1)
		cout << "FAIL" << endl;
	else
		cout << res << endl;
	return 0;
}