#include <string>
#include <vector>

using namespace std;

// 1. 상하 이동
// 알파벳별 최소 이동 횟수 : A~N -> 아래로, O~Z -> 위로
int alpha_to_move[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) 
{
    int answer = 0;
    int n = name.length();
    // 2.1 한 방향으로 조이스틱을 이동
    int min_move = n - 1;
    // BBBBAAAABA
    for (int i = 0;i < n;i++)
    {
        // 1. 상하 이동
        answer += alpha_to_move[name[i] - 'A'];
        
        // 2.2. 방향 전환
        int j = i + 1;
        while (j < n && name[j] == 'A')
            j++;
        // n-(j-i) : 전체 길이에서 이동해야할 위치
        min_move = min(min_move, i + n - j + min(i, n - j));
    }
    answer += min_move;
    return answer;
}

int main()
{
    solution("BBCAAAAAF");
    return 0;
}
