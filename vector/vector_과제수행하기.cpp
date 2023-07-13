#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string>& a, vector<string>& b)
{
	return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans)
{
	vector<string> answer;
	vector < pair<string, int>> waiting;

	int res = 0;
	sort(plans.begin(), plans.end(), compare);

	int cnt = plans.size();
	int i = 0;

	while (res != cnt)
	{
		// 마지막 플랜의 경우
		if (i == cnt - 1)
		{
			// 그냥 수행하고 (뒤에 계획없으니깐)
			answer.push_back(plans[i][0]);
			res++;
			// 웨이팅 처리
			while (!waiting.empty())
			{
				answer.push_back(waiting.back().first);
				waiting.pop_back();
			}
			break;
		}

		// 그게 아닐 경우 다음 플랜 시작 시간과 비교
		vector<string> plan = plans[i];
		vector<string> next_plan = plans[i + 1];

		int time = stoi(plan[1].substr(0, 2)) * 60 + stoi(plan[1].substr(3, 2));
		time += stoi(plan[2]);

		int next_time = stoi(next_plan[1].substr(0, 2)) * 60 + stoi(next_plan[1].substr(3, 2));

		// 시간이 남음 -> waiting 처리할 수 있음
		if (time < next_time)
		{
			answer.push_back(plan[0]);
			res++;

			// left : 쓸수있는 시간 
			int left = next_time - time;
			// waiting이 있다면 
			while (!waiting.empty() && left > 0)
			{
				pair<string, int > wait = waiting.back();
				if (wait.second <= left)
				{
					waiting.pop_back();
					left -= wait.second;
					answer.push_back(wait.first);
					res++;
				}
				else
				{
					waiting.back().second -= left;
					break;
				}
			}
		}
		// 딱맞아 떨어짐
		else if (time == next_time)
		{
			answer.push_back(plan[0]);
			res++;
		}
		// 시간 부족 -> waiting list로 
		else
		{
			waiting.push_back({ plan[0], time - next_time });
		}
		i++;
	}

	return answer;
}

int main()
{
	solution({ {"aaa", "12:00", "30"},
		{"bbb", "12:10", "30"},
		{"ccc", "14:00", "30"}
		});
	return 0;
}

