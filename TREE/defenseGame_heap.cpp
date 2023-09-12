#include <string>
#include <ios>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


// 라운드별 적의 순을 우선순위 큐에 저장
priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy)
{
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0;i < enemy.size();i++)
	{
		int e = enemy[i];
		pq.push(e);
		if (pq.size() > k)
		{
			sum += pq.top();
			pq.pop();
		}
		if (sum > n)
		{
			return i;
		}
	}
	return enemy.size();
}

int main() {
	solution(10, 1, {2,2,2,2,10});
	return 0;
}