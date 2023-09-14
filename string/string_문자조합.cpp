// https://school.programmers.co.kr/learn/courses/30/lessons/133499

#include <string>
#include <vector>

using namespace std;
/*
aya ye woo ma
*/

int better_solution(vector<string>babbling) {
    int answer = 0;
    for (string s : babbling)
    {
        int flag = 0;
        bool v = true;
        for (int i = 0;i < s.length();i++)
        {
            if (s.substr(i, 3) == "aya" && flag != 1) { flag = 1;i += 2; }
            else if (s.substr(i, 2) == "ma" && flag != 2) { flag = 2;i += 1; }
            else if (s.substr(i, 3) == "woo" && flag != 3) { flag = 3;i += 2; }
            else if (s.substr(i, 2) == "ye" && flag != 4) { flag = 4;i += 1; }
            else { v = false;break; }
        }
        if (v)
            answer++;
    }
}

int solution(vector<string> babbling) {

    int answer = 0;
    
    for (int i = 0;i < babbling.size();i++)
    {
        string str = babbling[i];
        bool isValid = true;
        // 1,2,3,4¼ø
        int cur = -1;
        for (int j = 0;j < str.size();)
        {
            if (isValid == false)
                break;
            char tmp = str[j];
            if (tmp == 'a')
            {
                if (j + 2 <= str.size())
                {
                    string sub_str = str.substr(j, 3);
                    if (sub_str == "aya")
                    {
                        if (cur != 1)
                        {
                            cur = 1;
                            j = j + 3;
                            continue;
                        }
                        else
                            isValid = false;
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if (tmp == 'y')
            {
                if (j + 1 <= str.size())
                {
                    string sub_str = str.substr(j, 2);
                    if (sub_str == "ye")
                    {
                        if (cur != 2)
                        {
                            cur = 2;
                            j = j + 2;
                            continue;
                        }
                        else
                            isValid = false;
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
                else
                {
                    isValid = false;
                    break;
                }
            }
            else if (tmp == 'w')
            {
                if (j + 2 <= str.size())
                {
                    string sub_str = str.substr(j, 3);
                    if (sub_str == "woo")
                    {
                        if (cur != 3)
                        {
                            cur = 3;
                            j = j + 3;
                            continue;
                        }
                        else
                            isValid = false;
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
                else
                {
                    isValid = false;
                    break;
                }

            }
            else if (tmp == 'm')
            {
                if (j + 1 <= str.size())
                {
                    string sub_str = str.substr(j, 2);
                    if (sub_str == "ma")
                    {
                        if (cur != 4)
                        {
                            cur = 4;
                            j = j + 2;
                            continue;
                        }
                        else
                            isValid = false;
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
                else
                {
                    isValid = false;
                    break;
                }

            }
            else
            {
                isValid = false;
                break;
            }
        }
        if (isValid)
            answer++;
    }

    return answer;
}

int main() {
    solution({"ayaye","uuu","yeye","yemawoo","ayaayaa"});
    return 0;
}