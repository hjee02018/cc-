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
	// �ִ��� ���� ������ ���� ���� (1-3/3-5 : �� ���� ����ð� = �� ���� ���۽ð� ok)
	
	// ���� ���� ���� �������� ����




	return 0;
}