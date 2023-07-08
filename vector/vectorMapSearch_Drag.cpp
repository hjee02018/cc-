// https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> solution(vector<string> wallpaper)
{
	// 가장 왼쪽 우측에 있는 좌표 ~ 가장 우측 하단에 있는 좌표 찾기
	vector<int> answer;

	int start_x = 0, start_y = 0, end_x = 0, end_y = 0;

	int w = wallpaper[0].size();
	int h = wallpaper.size();
	//cout << h << "행" << w << "열" << endl;

	int** my_map;
	my_map = new int* [h];
	for (int i = 0;i < h;i++)
		my_map[i] = new int[w];

	for (int i = 0;i < h;i++)
		for (int j = 0;j < w;j++)
			my_map[i][j] = wallpaper[i][j];
	//cout << i + 1 << "행" << j + 1 << "열 : " << my_map[i][j] << endl;
/*
* # : 35
* . : 46
*/
	vector<pair<int, int> >list;

	for (int i = 0;i < h;i++)
	{
		for (int j = 0;j < w;j++)
		{
			if (my_map[i][j] == 35)
			{
				list.push_back({ i, j });
			}
		}
	}
	cout << list.size() << endl;

	std::sort(list.begin(), list.end(),
		[](const auto& a, const auto& b) {
			return a.first < b.first;
		});

	int firstSmallest = list.front().first;
	int firstLargest = list.back().first;

	std::sort(list.begin(), list.end(),
		[](const auto& a, const auto& b) {
			return a.second < b.second;
		});

	int secondSmallest = list.front().second;
	int secondLargest = list.back().second;


	answer.push_back(firstSmallest);
	answer.push_back(secondSmallest);
	answer.push_back(firstLargest + 1);
	answer.push_back(secondLargest + 1);

	return answer;
}

int main4()
{
	solution({ ".#...", "..#..", "...#." });
	return 0;

}