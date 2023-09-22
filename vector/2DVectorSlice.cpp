#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
	vector<int> answer;
	int top = 0;
	int bottom = 0;
	for (long long i = left;i < right + 1;i++)
	{
		// top : За
		// bottom : ї­
		top = i / n;
		bottom = i % n;
		if (top >= bottom + 1)
			bottom += top - bottom;
		answer.push_back(bottom + 1);
	}
	return answer;
}

