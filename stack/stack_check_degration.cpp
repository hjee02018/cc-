#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<int> prices) 
{
    vector<int> answer;
    int n=prices.size();
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        for(;j<n;j++)
            if(prices[j]<prices[i])
                break;
        // 떨어지는 경우
        if(j!=n)
            answer.push_back(j-i);
        else
            answer.push_back(n-i-1);
    }
    
    return answer;
}
