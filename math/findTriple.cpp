#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 합이 0인 조합의 개수 구하기
int solution(vector<int> number) 
{
    int answer = 0;
    for (int i = 0;i < number.size() - 2;i++)
        for (int j = i + 1;j < number.size() - 1;j++)
            for (int k = j + 1;k < number.size();k++)
                if (number[i] + number[j] + number[k] == 0)
                    answer++;

    return answer;
}