// https://school.programmers.co.kr/learn/courses/30/lessons/147355
#include <string>
#include <vector>

using namespace std;
/*
* int�� �ƴ� long long int�� ����ؾ��ϴ� ����
* : 1<=p<=18 (�� p�� ���̰�18, ������ 18�ڸ����� Ŀ���ؾ���)
* int�� 10�ڸ������� Ŀ���ϹǷ� 
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