#include <string>
#include <vector>
#include <iostream>
using namespace std;

// ��ȿ������ �˰���
//int getGCD(int num)
//{
//    if (num == 1)
//        return 1;
//    int res = 2;
//    for (int i = 2;i < num;i++)
//    {
//        if (num % i == 0)
//            res++;
//    }
//    return res;
//}

int solution(int number, int limit, int power) 
{
    int answer = 0;
    // 1���� number���� ������ ����� ����
    vector<int> res(number+1);
    for (int i = 1;i <= number;i++)
    {
        for (int j = 1;i * j<= number;j++)
        {
            res[i * j] += 1;
        }
    }
    for (int i = 1;i < res.size();i++)
    {
        if (res[i] > limit)
            answer += power;
        else
            answer += res[i];
    }

    return answer;
}

int main_getGCD()
{
    solution(5, 3, 2);
    return 0;
}
