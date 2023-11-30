#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// n-> 3진법
// 앞뒤로 뒤집기
// -> 10진법

int solution(int n) 
{
    int answer = 0;
    vector<int> t;
    // STEP1. 3진법 구하기
    while(n>0)
    {
        t.insert(t.begin(),n%3);
        n/=3;
    }
    // STEP2. 3진법 뒤집기
    reverse(t.begin(), t.end());
    
    // STEP3. 10진법으로 표현
    for(int i=t.size()-1;i>=0;i--)
    {
        int no = pow(3,(t.size()-i-1));
        answer+= (no * t[i]);
    }
    
    return answer;
}
