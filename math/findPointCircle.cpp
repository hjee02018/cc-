// https://school.programmers.co.kr/learn/courses/30/lessons/181187

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;
    long long n = r2 - r1;
    long long n2 = 0;
    // 1사분면에서의 점 x 4
    for (long long i = 1;i < r2;i++)
    {
        long long tmp = i * i;
        int val1, val2;
        val1 = (int)floor(sqrt(pow(r2, 2) - pow(i, 2)));
        if (i < r1)
        {
            val2 = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        }
        else
            val2 = 1;
        n2 += val1 - val2 + 1;
    }

    // 축위의 점 
    answer += (n + 1) * 4;
    answer += n2 * 4;



    return answer;
}