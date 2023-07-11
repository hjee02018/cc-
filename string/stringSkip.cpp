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
    // s를 index만큼 뒤의 알파벳으로 skip의 문자는 제외하고

    for (int i = 0;i < s.size();i++)
    {
        char res = s[i];
        for (int j = 0;j < index;)
        {
            res++;
            // z 초과인 경우 ; a로 초기화
            if (res == 'z' + 1) res = 'a';
            // skip에 포함되지 않는 경우에만 +1
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