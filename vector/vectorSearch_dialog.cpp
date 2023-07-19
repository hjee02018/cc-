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
	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);
	return dx + dy;
}
pair<int, int> getLoc(int val)
{
	if (val == 2)
		return { 0,1 };
	else if (val == 5)
		return { 1,1 };
	else if (val == 8)
		return { 2,1 };
	else
		return { 3,1 };
}

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	// 행,열
	pair<int, int>left = {3,0};
	pair<int, int>right = { 3,2 };

	for (int i = 0;i < numbers.size();i++)
	{
		cout << answer << endl;
		int num = numbers[i];
		if (num == 1 || num == 4 || num == 7)
		{
			answer += "L";
			left.first = num / 3;
			left.second = 0;
		}
		else if (num == 3 || num == 6 || num == 9)
		{
			answer += "R";
			right.first = num / 3-1;
			right.second = 2;
		}
		else
		{
			int dis1, dis2;
			switch (num)
			{
			case 2:
				dis1 = getDistance(left, { 0,1 });
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
			if (dis1 > dis2)
			{
				answer += "R";
				right.first = getLoc(num).first;
				right.second = getLoc(num).second;
			}
			else if (dis1 < dis2)
			{
				answer += "L";
				left.first = getLoc(num).first;
				left.second = getLoc(num).second;
			}
			else
			{
				if (hand == "right")
				{
					right.first = getLoc(num).first;
					right.second = getLoc(num).second;
					answer += "R";
				}
				else
				{
					answer += "L";
					left.first = getLoc(num).first;
					left.second = getLoc(num).second;
				}
			}
		}
	}
	return answer;
}


int main()
{
	solution({7,0,8,2,8,3,1,4,7,6,2}, "left");
	return 0;
}