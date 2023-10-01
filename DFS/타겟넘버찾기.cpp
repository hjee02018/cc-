#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int>numbers,int target, int sum, int idx)
{
    // 종료 조건
    // 1. idx가 끝에 도달
    // 1.1 target을 만족 (answer+=1)
    // 1.2 target을 만족 x 
    if (idx == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    DFS(numbers, target, sum + numbers[idx], idx + 1);
    DFS(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, target, 0, 0);
    return answer;
}