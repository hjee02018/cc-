// https://school.programmers.co.kr/learn/courses/30/lessons/147355
#include <string>
#include <vector>

using namespace std;
/*
* int가 아닌 long long int를 사용해야하는 이유
* : 1<=p<=18 (즉 p의 길이가18, 정수가 18자리까지 커버해야함)
* int는 10자리까지만 커버하므로 
*/
int solution(string t, string p) 
{
    int answer = 0;
    int len = p.size();
    long long int input = stoll(p);
    for (int i = 0;i < t.length() - len+1;i++)
    {
        string tmp = t.substr(i, len);
        if (stoll(tmp) <= input)
            answer++;
    }

    return answer;
}


int main()
{
    solution("10203", "15");
    return 0;
}