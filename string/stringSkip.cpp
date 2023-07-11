// https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <string>
#include <vector>

using namespace std;

bool isSkip(string skip, char c)
{
    for (int i = 0;i < skip.size();i++)
        if (skip[i] == c)
            return true;
    return false;
}

string solution(string s, string skip, int index) 
{
    string answer = "";
    // s�� index��ŭ ���� ���ĺ����� skip�� ���ڴ� �����ϰ�

    for (int i = 0;i < s.size();i++)
    {
        char res = s[i];
        for (int j = 0;j < index;)
        {
            res++;
            // z �ʰ��� ��� ; a�� �ʱ�ȭ
            if (res == 'z' + 1) res = 'a';
            // skip�� ���Ե��� �ʴ� ��쿡�� +1
            if (!isSkip(skip, res))
                j++;
        }
        answer.push_back(res);
    }

    return answer;
}

int main()
{
    solution("aukks", "wbqd", 5);
    return 0;
}