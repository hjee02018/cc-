#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
/*
* 왼손(*)
* 오른손(#)
* 상하좌우이동
*/
// 2,5,8,0 라인일 때 고려 못함

// a,b사이 거리 계산
int getDistance(pair<int, int> a, pair<int, int>b)
{
	int dis;

	return dis;
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	// 행,열
	pair<int, int>left;
	pair<int, int>right;

	for (int i = 0;i < numbers.size();i++)
	{
		int num = numbers[i];
		if (num == 1 || num == 4 || num == 7)
		{
			answer += "L";
			left.first = 3 - num / 3;
			left.second = 0;
		}
		else if (num == 3 || num == 6 || num == 9)
		{
			answer += "R";
			right.first = 3 - num / 3;
			right.second = 0;
		}
		else
		{
			int dis1, dis2;
			switch (num)
			{
			case 2:
				dis1 = getDistance(left, {0,1});
				dis2 = getDistance(right, { 0,1 });
				break;
			case 5:
				dis1 = getDistance(left, { 1,1 });
				dis2 = getDistance(right, { 1,1 });
				break;
			case 8:
				dis1 = getDistance(left, { 2,1 });
				dis2 = getDistance(right, { 2,1 });
				break;
			case 0:
				dis1 = getDistance(left, { 3,1 });
				dis2 = getDistance(right, { 3,1 });
				break;
			default:
				break;
			}

		}
	}

	return answer;
}