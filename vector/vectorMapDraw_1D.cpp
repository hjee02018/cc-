//https://school.programmers.co.kr/learn/courses/30/lessons/161989


#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section)
{
	int answer = 0;
	int* road;
	road = new int[n];

	for (int i = 0; i < n; i++)
		road[i] = 1;

	for (int i = 0;i < section.size();i++)
		road[section[i]-1] = 0;

	for (int i = 0;i < n;i++)
		cout << road[i] << endl;


	for (int i = 0;i < n;i++)
	{
		if (road[i] == 0)
		{
			// Ä¥ÇØ¾ßÇÔ
			answer++;
			if (i + m < n)
			{
				for (int k = i;k < i + m;k++)
					road[k] = 1;
			}
			else
			{
				for (int k = i;k < n;k++)
					road[k] = 1;
			}
		}
	}

	cout << answer;
	return answer;
}

int main5()
{
	solution(4, 1, { 1,2,3,4 });
	return 0;
}