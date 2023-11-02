/*
* greedy 알고리즘 : 최적해 탐색 알고리즘
* 단계마다 현재 상황에서 최선의 선택을 하는 방식 
* -> 최종적으로 전체 문제의 최적해를 찾는 것이 목표
* but, 항상 최적해를 보장하는 것이 아님
*/

// 1. 거스름돈 예시
// - 사용자 입력 값에 대해 가장 적은 동전 개수로 거슬러 주고자 한다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> giveChange(int amount, vector<int> denominations)
{
	vector<int> change;
	int i = denominations.size() - 1;
	while (amount > 0 && i >= 0)
	{
		if (denominations[i] <= amount && i>=0)
		{
			// 거스름돈-동전
			change.push_back(denominations[i]);
			amount -= denominations[i];
		}
		else
		{
			i--;
		}
	}
	return change;

}

int main1()
{
	// amount : 거스름돈
	int amount;
	cin >> amount;
	// 거스름돈의 종류
	vector<int> denominations = { 500,100,50,10 };
	vector<int> change = giveChange(amount, denominations);
	for (int coin : change)
	{
		cout << coin << endl;
	}
	return 0;
}

// 2.
// https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=cpp
// lost : 잃어버린 학생
// reserve :여분 가져온 학생

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<int> check(n, 1);
	for (auto i : lost)
		check[i - 1]--;
	for (auto i : reserve)
		check[i - 1]++;

	for (auto i = 0;i < check.size();i++)
	{
		// 체육복 없음
		if (!check[i])
		{
			// 앞사람한테 빌리기
			if (i != 0 && check[i - 1] == 2)
			{
				check[i - 1]--;
				check[i]++;
			}
			else if (i < check.size() - 1 && check[i + 1] == 2)
			{
				check[i + 1]--;
				check[i]++;
			}
		}
	}
	for (int a = 0;a < check.size();a++)
		if (check[a] != 0)
			answer++;
	return answer;
}

int main()
{
	solution(5, { 2,4 }, { 3 });
	return 0;
}