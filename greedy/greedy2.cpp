/*
* greedy �˰��� : ������ Ž�� �˰���
* �ܰ踶�� ���� ��Ȳ���� �ּ��� ������ �ϴ� ��� 
* -> ���������� ��ü ������ �����ظ� ã�� ���� ��ǥ
* but, �׻� �����ظ� �����ϴ� ���� �ƴ�
*/

// 1. �Ž����� ����
// - ����� �Է� ���� ���� ���� ���� ���� ������ �Ž��� �ְ��� �Ѵ�.

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
			// �Ž�����-����
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
	// amount : �Ž�����
	int amount;
	cin >> amount;
	// �Ž������� ����
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
// lost : �Ҿ���� �л�
// reserve :���� ������ �л�

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
		// ü���� ����
		if (!check[i])
		{
			// �ջ������ ������
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