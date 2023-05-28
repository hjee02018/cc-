#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main5(int argc, char** argv)
{
	int N;
	int res = 1;
	vector<pair<int, int>> lec;
	int s, f;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> f;
		lec.push_back({ f,s });
	}
	sort(lec.begin(), lec.end());
	int cur_end = lec[0].first;
	for (int i = 1; i < N; i++)
	{
		if (lec[i].second >= cur_end)
		{
			cur_end = lec[i].first;
			res++;
		}
	}
	cout << res << endl;
	// 최대한 많은 개수의 강의 배정 (1-3/3-5 : 앞 수업 종료시간 = 뒷 수업 시작시간 ok)
	
	// 종료 시점 기준 오름차순 정렬




	return 0;
}