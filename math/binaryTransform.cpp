#include <string>
#include <vector>

using namespace std;
string getbinary(int no)
{
    if (no == 0)
        return "0"; // 예외 처리: 0의 경우
    string res = "";
    while (no > 0)
    {
        res = (char)((no % 2) + '0') + res; // 나머지를 문자로 변환하여 앞에 추가
        no /= 2;
    }
    return res;
}
vector<int> solution(string s)
{
    vector<int> answer;
    int no = 0;
    int cnt = 0;
    while (1)
    {
        if (s == "1")
            break;
        string tmp = "";
        // 0 제거
        for (int i = 0;i < s.length();i++)
        {
            if (s[i] == '0')
                cnt++;
            else
                tmp += s[i];
        }
  
        no++;
        // 제거 후 이진 변환
        s = getbinary(tmp.length());
    }
    answer.push_back(no);
    answer.push_back(cnt);
    return answer;
}
