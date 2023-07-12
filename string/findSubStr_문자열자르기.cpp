
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int len = s.length();
	int i, j;
	for (i = 0;i < len;i++)
	{
		int same = 0, diff = 0;
		int x = s[i];
		for (j = i;j < len;j++)
		{

			if (s[j] == s[i])
				same++;
			else
				diff++;
			if (same == diff)
			{
				answer++;
				i = j;
				break;
			}
			if (j == len - 1 && same!=diff)
			{
				answer++;
				// i=j; 구문을 해야 마지막 for문을 수행하지 않음
				i = j;
				break;
			}
		}
	}
	return answer;
}

int main_substring()
{
	solution("bananannn");
	return 0;
}


//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int num = 0;
//
//void substring(string s)
//{
//    int first = s[0];
//    int same = 1;
//    int diff = 0;
//    if (s.length() <= 1)
//    {
//        //num++;
//        return;
//    }
//    for (int i = 1;i < s.length();i++)
//    {
//
//        if (i == s.length() - 1)
//        {
//            if (s[i] != first)
//                num++;
//        }
//        if (same == diff)
//        {
//            num++;
//            cout << s.substr(0, i)<<endl;
//            substring(s.substr(i));
//            break;
//        }
//        if (s[i] == first)
//            same++;
//        else if (s[i] != first)
//            diff++;
//    }
//}
//
//
//int solution(string s) {
//    int answer = 0;
//
//    substring(s);
//    answer = num;
//
//    return answer;
//}
//
//
//int main()
//{
//    solution("abracadabra");
//    return 0;
//}