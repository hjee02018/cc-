#include <string>
#include <vector>

using namespace std;
// 기둥 3개
// 올라갈수록 작은게 쌓임
// 1번에 1개만 이동 & 큰게 작은거 위에 있을 수 x
// 1,2,3기둥
// 1기둥에 nㄱ래의 원판 -> 3번으로 이동
vector<vector<int>> answer;
void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        answer.push_back({from,to});
        return;        
    }
    // 1. n-1개이동
    hanoi(n - 1, from, to, by);
    // 2. 최하단 이동
    answer.push_back({ from,to });
    hanoi(n - 1, by, from, to);
}

vector<vector<int>> solution(int n)
{
    if (n == 1)
        answer.push_back({ 1,3 });
    hanoi(n, 1, 2, 3);
    return answer;
}
