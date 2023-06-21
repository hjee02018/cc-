// https://softeer.ai/practice/info.do?idx=1&eid=411
// DFS 
#include<iostream>
#include <vector>

using namespace std;

int map[5][100];
static int N;
static int M;
int next_x[4] = { -1,1,0,0 };
int next_y[4] = { 0,0,1,-1 };
vector<pair<int, int>> next_map;


bool check(int i, int j)
{
	int arr[4] = { 0, };
	int cur_x = i;
	int cur_y = j;
	int count = 0;
	// 내부인지 아닌지 확인
	for (int i = 0;i < 4;i++)
	{
		int x = i + next_x[i];
		int y = j + next_y[i];
		if (map[x][y] == 1)
		{
			count++;
			arr[i] = 1;
		}
	}
	if (count > 2)
		return false;
	else if ((arr[0] == 1 && arr[1] == 1) || (arr[2] == 1 && arr[3] == 1))
		return false;
	else
		return true;
}

bool checkAdj()
{
	cout << N << M << endl;
	bool isDone = true;

	while (!next_map.empty())
	{
		int i = next_map.back().first;
		int j = next_map.back().second;
		map[i][j] = 0;
		next_map.pop_back();
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			if (map[i][j] == 1)
			{
				isDone = false;
				if (check(i, j))
					next_map.push_back({ i, j });
			}
		}
	}
	return isDone;
}

int main(int argc, char** argv)
{
	
	cin >> N >> M;
	cout << N << M;
	// N행M열
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			int tmp;
			cin >> tmp;
			// 0 : 얼음없, 1: 얼음있
			map[i][j] = tmp;
		}
	}
	int count = 0;

	while (!checkAdj())
	{
		count++;
	}

	cout << count << endl;
	return 0;
}