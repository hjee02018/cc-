#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int createParam(int num)
{
    int res = 1;
    for (int i = 0;i < num - 1;i++)
        res *= 10;
    return res;
}

// storey : 시작 위치 -> 0으로 이동해야함
int solution(int storey)
{
    int answer = 0;
    int len = log10(abs(storey)) + 1;
    if (storey == 0)
        return 0;

    for (int i = 0;i < len;i++)
    {
        int par = createParam(log10(abs(storey)) + 1);
        // tmp : 554
        int tmp = storey % par;
        // tmp2 : 446
        int tmp2 = par - tmp;
        if (tmp == 0)
        {
            answer += storey / par;
            break;
        }
        else if (tmp < tmp2)
        {
            answer += storey / par;
            storey = tmp;
        }
        else
        {
            answer += storey / par + 1;
            storey = tmp2;
        }
    }

    return answer;
}


int main()
{
    solution(2554);
    return 0;
}