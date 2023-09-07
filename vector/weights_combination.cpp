#include <string>
#include <vector>

using namespace std;
/*
 - x2 x3 x4
 - 무게1 x 거리1 = 무게2 x 거리2 -> 무게1과 무게2는 짝꿍
 - 핵심은 중첩반복문을 사용하지 않는 것.
*/

long long solution(vector<int> weights) 
{
    long long answer = 0;
    vector<long long> cnt(1001, 0);
    for (int i = 0;i < weights.size();i++)
        cnt[weights[i]]++;

    /*
    * case1. 1:2 (=2:4)
    * case2. 2:3
    * case3. 3:4
    */
    for (int i = 0;i < weights.size();i++)
    {
        if (weights[i] % 2 == 0)
        {
            int find = (weights[i] * 3) / 2;
            if (find <= 1000)
                answer += cnt[find];
        }
        if (weights[i] % 3 == 0)
        {
            int find = (weights[i] * 4) / 3;
            if (find <= 1000)
                answer += cnt[find];
        }
        int find = weights[i] * 2;
        if (find <= 1000)
            answer += cnt[find];
    }


    // 몸무게가 같은 사람의 수
    for (int i = 100;i <= 1000;i++)
    {
        if (cnt[i] >= 2)
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2;
    }

    return answer;
}