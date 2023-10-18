#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int n = s.length();
    int min = n;
    for (int i = 1;i <= n / 2;i++)
    {
        int cnt = 1;
        string res = "";
        string tmp = "";
        int j = 0;
        for (;j < n - i;j += i)
        {
            if (s.substr(j, i) == s.substr(j + i, i))
            {
                cnt++;
                tmp = s.substr(j, i);
            }
            else
            {
                if (cnt > 1)
                {
                    res += to_string(cnt);
                    cnt = 1;
                    res += tmp;
                    tmp = "";
                }
                else
                {
                    res += s.substr(j, i);
                }
            }

        }
        if (cnt > 1)
        {
            res += to_string(cnt);
            res += s.substr(n - i);
        }
        else
        {
            res += s.substr(j);
        }
        cout << i << "´ÜÀ§ : " << res << endl;
        if (res.length() < min)
            min = res.length();
    }

    return min;
}

int main()
{
    solution("aaaaaaaaaaaabcd");
    return 0;
}