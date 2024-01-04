//https://school.programmers.co.kr/learn/courses/30/lessons/250136
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
// n행 m열
int n, m;
// 방문 여부
bool v[500][500] = { false, };
vector<vector<int>> mp;
// 열에 포함된 석유 덩어리의 크기
map<int, vector<int>> row;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 1;
// 열 포함 추가
map<int, int> row_cnt;
void dfs(int i, int j)
{
	row_cnt[j]++;
	v[i][j] = true;
	for (int k = 0;k < 4;k++)
	{
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (mp[nx][ny] == 1 && v[nx][ny] == false)
		{
			cnt++;
			dfs(nx, ny);
		}
	}
}
int solution(vector<vector<int>> land)
{
	int answer = 0;
	n = land.size();
	m = land[0].size();
	mp = land;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (land[i][j] == 1 && v[i][j] == false)
			{
				v[i][j] = true;
				dfs(i, j);
				int sz = cnt;
                
				// row_cnt 계산
				for (auto iter = row_cnt.begin();iter != row_cnt.end();iter++)
					row[iter->first].push_back(sz);
                
				// 초기화
				map<int, int> tmp;
				row_cnt = tmp;
				cnt = 1;
			}
		}
	}
	for (auto iter = row.begin();iter != row.end();iter++)
	{
		int sum = 0;
		vector<int> rl = iter->second;
		for (int i = 0;i < rl.size();i++)
			sum += rl[i];
		if (sum > answer)
			answer = sum;
	}
	return answer;
}
