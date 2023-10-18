#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> cards)
{
    int answer = 1;
    // i번째 박스 열어봤는지
    map<int, bool> check;
    int cur = 0;
    int cnt = 0;
    check[cur + 1] = true;
    int idx = 0;
    while (1)
    {
        if (idx >= cards.size())
            break;
        int nx = cards[cur];
        if (check[nx] != true)
        {
            cur = nx - 1;
            cnt++;
        }
        else
        {
            answer *= cnt;
            cnt = 0;
            cur = idx++;
        }
    }


    return answer;
}

int main()
{
    solution([8, 6, 3, 7, 2, 5, 1, 4]);
    return 0;
}