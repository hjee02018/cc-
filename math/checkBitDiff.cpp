#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (int i = 0;i < numbers.size();i++)
    {
        long long no = numbers[i];
        if (no == 2)
        {
            answer.push_back(3);
            continue;
        }
        if (no % 2 == 0)
        {
            answer.push_back(no + 1);
            continue;
        }
        else
        {
            // 뒤에서부터 처음으로 '0'인 곳->'1'
            // '1'이 나온 다음 위치에서부터 처음으로 '1'인 숫자 -> '0'
            
            int npos = 0;
            while (npos <= 63)
            {
                //1LL = 1 (long long) = 0000...0001 
                // no의 npos 위치가 0이라면
                if ((no & (1LL << npos)) == 0)
                    break;
                npos++;
            }
            int xpos = npos-1;
            bool isval = false;
            while (xpos >= 0)
            {
                if ((no & (1LL << xpos)) != 0)
                {
                    isval = true;
                    break;
                }
                xpos--;
            }
            no += pow(2, npos);
            if(isval)
				no -= pow(2, xpos);
            answer.push_back(no);
        }
    }
    return answer;
}
