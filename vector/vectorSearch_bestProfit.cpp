// Q6 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(std::vector<int> prices, int k) 
{
    int answer = 0;
    
    // 매수가
    int buy = 0;
    vector<vector<int>> price_per_day;
    for (int i = 0;i < prices.size();i++)
    {
        price_per_day.push_back({prices[i],i});
    }
    sort(price_per_day.begin(), price_per_day.end());

    for (int i = 0;i < price_per_day.size();i++)
    {
        int idx = price_per_day[i].back();
        int buy = price_per_day[i].front();
        int prof = 0;
        // 구간이 존재하지 않는 경우
        if (prices.size() - idx <= k)
            continue;
        // 수익 구간 확인
        for (int j = idx;j < prices.size();j++)
        {
            prof += prices[j] - buy;
        }
        if (answer < prof)
            answer = prof;
    }
    cout << answer << endl;
    if (answer == 0)
        return -1;
    else 
		return answer;
}

int main()
{
    // 3주 매수, 3일동안 매도 
    solution({10,7,8,5,8,7,6,2,9}, 3);
    return 0;
}



//#include <vector>
//
//using namespace std;
//
//int solution(vector<int> schedules)
//{
//    int answer = 0;
//    int len = schedules.size();
//
//    if (schedules.size() == 1)
//    {
//        answer = schedules[0];
//    }
//    else if (schedules.size() == 2)
//    {
//        answer = max(schedules[0], schedules[1]);
//    }
//    else 
//    {
//        vector<int> res(len, 0);
//
//        res[0] = schedules[0];
//        res[1] = max(schedules[0], schedules[1]);
//
//
//        // max 
//        for (int i = 2; i < len; i++) 
//        {
//            res[i] = max(res[i - 1], res[i - 2] + schedules[i]);
//        }
//
//        answer = res[len - 1];
//    }
//
//    return answer;
//}
//
////#include <string>
////#include <vector>
////#include <iostream>
////
////using namespace std;
////
////string getLongestSubstring(const string& str) 
////{
////    int len = str.length();
////    string longestSubstring = "";
////
////    for (int i = 0; i < len; i++) 
////    {
////        for (int j = i + 1; j <= len; j++) 
////        {
////            string substring = str.substr(i, j - i);
////            if (substring.length() > longestSubstring.length()) 
////            {
////                longestSubstring = substring;
////            }
////        }
////    }
////
////    return longestSubstring;
////}
////
////vector<string> solution(vector<string> merchantNames) {
////    vector<string> answer;
////    
////    for (const string& name : merchantNames) {
////        string longestSubstring = getLongestSubstring(name);
////        answer.push_back(longestSubstring);
////    }
////
////    return answer;
////}
////
////int main()
////{
////
////    return 0;
////}
////
////
//////
//////#include <string>
//////#include <vector>
//////#include <iostream>
//////#include <algorithm>
//////
//////using namespace std;
//////
//////int solution(string s, int N)
//////{
//////    int answer;
//////    vector<string> result;
//////    int len = s.length();
//////
//////    for (int i = 0; i <= len - N; i++)
//////    {
//////        string substring = s.substr(i, N);
//////        int cnt = 0;
//////
//////        // 1부터 N까지의 숫자가 substring에 한 번씩 등장하는지 확인
//////        for (int j = 1; j <= N; j++)
//////        {
//////            if (substring.find(to_string(j)) != string::npos)
//////                cnt++;
//////        }
//////
//////        // 모든 숫자가 한 번씩 등장하면 결과에 추가
//////        if (cnt == N)
//////            result.push_back(substring);
//////    }
//////
//////    int max = stoi(result[0]);
//////    for (int i = 0;i < result.size();i++)
//////        if (stoi(result[i]) > max)
//////            max = stoi(result[i]);
//////
//////    answer = max;
//////    return answer;
//////}
//////
//////
////////#include <string>
////////#include <vector>
////////#include <iostream>
////////using namespace std;
////////
////////int solution(string s, int N) 
////////{
////////    int answer = 0;
////////    vector<int>list;
////////    int* find = new int[N];
////////
////////    cout << sizeof(find)/sizeof(int) << endl;
////////    // 0 : 등장안함,
////////    // 1 : 등장
////////    for (int i = 0;i < N;i++)
////////        find[i] = 0;
////////
////////    for (int i = 0;i < s.size();i++)
////////    {
////////        //i부터~n까지의 sub
////////        string substring = s.substr(i, N);
////////        bool isValid = true;
////////        int cnt = 0;
////////        for (int j = 0;j < N;j++)
////////        {
////////            if (substring[j]-'0' > N)
////////            {
////////                break;
////////                isValid = false;
////////            }
////////            if (find[substring[j]-'0'] == 0)
////////            {
////////                find[substring[j-'0']] = 1;
////////                cnt++;
////////            }
////////            else
////////            {
////////                break;
////////                isValid = false;
////////            }
////////        }
////////        if (isValid&&cnt==N)
////////        {
////////            cout << stoi(substring) << endl;
////////            list.push_back(stoi(substring));
////////        }
////////    }
////////    if (!list.empty()) {
////////        answer = *max_element(list.begin(), list.end());
////////    }
////////
////////    return answer;
////////}
////////
////////int main()
////////{
////////    solution({"1341232125"}, 2);
////////    return 0;
////////}
////////
//////////#include <string>
//////////#include <vector>
//////////
//////////using namespace std;
//////////
//////////string getLongestString(const vector<string>& strings)
//////////{
//////////    string longestString = "";
//////////    for (const string& str : strings)
//////////    {
//////////        if (str.length() > longestString.length())
//////////            longestString = str;
//////////    }
//////////    return longestString;
//////////}
//////////
//////////
//////////
//////////vector<string> solution(vector<string> merchantNames) {
//////////    vector<string> answer;
//////////
//////////    string longestString = getLongestString(merchantNames);
//////////
//////////    if (!longestString.empty())
//////////        answer.push_back(longestString);
//////////
//////////    return answer;
//////////}
////
////
//////
//////#include <string>
//////#include <vector>
//////#include <iostream>
//////
//////using namespace std;
//////
//////string getLongestSubstring(const string& str)
//////{
//////    int len = str.length();
//////    string longestSubstring = "";
//////
//////    for (int i = 0; i < len; i++)
//////    {
//////        for (int j = i + 1; j <= len; j++)
//////        {
//////            string substring = str.substr(i, j - i);
//////            if (substring.length() > longestSubstring.length())
//////            {
//////                longestSubstring = substring;
//////            }
//////        }
//////    }
//////
//////    return longestSubstring;
//////}
//////
//////vector<string> solution(vector<string> merchantNames) {
//////    vector<string> answer;
//////
//////    for (const string& name : merchantNames) {
//////        string longestSubstring = getLongestSubstring(name);
//////        answer.push_back(longestSubstring);
//////    }
//////
//////    return answer;
//////}
//////
//////int main()
//////{
//////
//////    return 0;
//////}
//////
//////
////////
////////#include <string>
////////#include <vector>
////////#include <iostream>
////////#include <algorithm>
////////
////////using namespace std;
////////
////////int solution(string s, int N)
////////{
////////    int answer;
////////    vector<string> result;
////////    int len = s.length();
////////
////////    for (int i = 0; i <= len - N; i++)
////////    {
////////        string substring = s.substr(i, N);
////////        int cnt = 0;
////////
////////        // 1부터 N까지의 숫자가 substring에 한 번씩 등장하는지 확인
////////        for (int j = 1; j <= N; j++)
////////        {
////////            if (substring.find(to_string(j)) != string::npos)
////////                cnt++;
////////        }
////////
////////        // 모든 숫자가 한 번씩 등장하면 결과에 추가
////////        if (cnt == N)
////////            result.push_back(substring);
////////    }
////////
////////    int max = stoi(result[0]);
////////    for (int i = 0;i < result.size();i++)
////////        if (stoi(result[i]) > max)
////////            max = stoi(result[i]);
////////
////////    answer = max;
////////    return answer;
////////}
////////
////////
//////////#include <string>
//////////#include <vector>
//////////#include <iostream>
//////////using namespace std;
//////////
//////////int solution(string s, int N) 
//////////{
//////////    int answer = 0;
//////////    vector<int>list;
//////////    int* find = new int[N];
//////////
//////////    cout << sizeof(find)/sizeof(int) << endl;
//////////    // 0 : 등장안함,
//////////    // 1 : 등장
//////////    for (int i = 0;i < N;i++)
//////////        find[i] = 0;
//////////
//////////    for (int i = 0;i < s.size();i++)
//////////    {
//////////        //i부터~n까지의 sub
//////////        string substring = s.substr(i, N);
//////////        bool isValid = true;
//////////        int cnt = 0;
//////////        for (int j = 0;j < N;j++)
//////////        {
//////////            if (substring[j]-'0' > N)
//////////            {
//////////                break;
//////////                isValid = false;
//////////            }
//////////            if (find[substring[j]-'0'] == 0)
//////////            {
//////////                find[substring[j-'0']] = 1;
//////////                cnt++;
//////////            }
//////////            else
//////////            {
//////////                break;
//////////                isValid = false;
//////////            }
//////////        }
//////////        if (isValid&&cnt==N)
//////////        {
//////////            cout << stoi(substring) << endl;
//////////            list.push_back(stoi(substring));
//////////        }
//////////    }
//////////    if (!list.empty()) {
//////////        answer = *max_element(list.begin(), list.end());
//////////    }
//////////
//////////    return answer;
//////////}
//////////
//////////int main()
//////////{
//////////    solution({"1341232125"}, 2);
//////////    return 0;
//////////}
//////////
////////////#include <string>
////////////#include <vector>
////////////
////////////using namespace std;
////////////
////////////string getLongestString(const vector<string>& strings)
////////////{
////////////    string longestString = "";
////////////    for (const string& str : strings)
////////////    {
////////////        if (str.length() > longestString.length())
////////////            longestString = str;
////////////    }
////////////    return longestString;
////////////}
////////////
////////////
////////////
////////////vector<string> solution(vector<string> merchantNames) {
////////////    vector<string> answer;
////////////
////////////    string longestString = getLongestString(merchantNames);
////////////
////////////    if (!longestString.empty())
////////////        answer.push_back(longestString);
////////////
////////////    return answer;
////////////}
//////
//////
//////
////////#include <string>
////////#include <vector>
////////#include <iostream>
////////
////////using namespace std;
////////
////////string getLongestSubstring(const string& str) 
////////{
////////    int len = str.length();
////////    string longestSubstring = "";
////////
////////    for (int i = 0; i < len; i++) 
////////    {
////////        for (int j = i + 1; j <= len; j++) 
////////        {
////////            string substring = str.substr(i, j - i);
////////            if (substring.length() > longestSubstring.length()) 
////////            {
////////                longestSubstring = substring;
////////            }
////////        }
////////    }
////////
////////    return longestSubstring;
////////}
////////
////////vector<string> solution(vector<string> merchantNames) {
////////    vector<string> answer;
////////    
////////    for (const string& name : merchantNames) {
////////        string longestSubstring = getLongestSubstring(name);
////////        answer.push_back(longestSubstring);
////////    }
////////
////////    return answer;
////////}
////////
////////int main()
////////{
////////
////////    return 0;
////////}
////////
////////
//////////
//////////#include <string>
//////////#include <vector>
//////////#include <iostream>
//////////#include <algorithm>
//////////
//////////using namespace std;
//////////
//////////int solution(string s, int N)
//////////{
//////////    int answer;
//////////    vector<string> result;
//////////    int len = s.length();
//////////
//////////    for (int i = 0; i <= len - N; i++)
//////////    {
//////////        string substring = s.substr(i, N);
//////////        int cnt = 0;
//////////
//////////        // 1부터 N까지의 숫자가 substring에 한 번씩 등장하는지 확인
//////////        for (int j = 1; j <= N; j++)
//////////        {
//////////            if (substring.find(to_string(j)) != string::npos)
//////////                cnt++;
//////////        }
//////////
//////////        // 모든 숫자가 한 번씩 등장하면 결과에 추가
//////////        if (cnt == N)
//////////            result.push_back(substring);
//////////    }
//////////
//////////    int max = stoi(result[0]);
//////////    for (int i = 0;i < result.size();i++)
//////////        if (stoi(result[i]) > max)
//////////            max = stoi(result[i]);
//////////
//////////    answer = max;
//////////    return answer;
//////////}
//////////
//////////
////////////#include <string>
////////////#include <vector>
////////////#include <iostream>
////////////using namespace std;
////////////
////////////int solution(string s, int N) 
////////////{
////////////    int answer = 0;
////////////    vector<int>list;
////////////    int* find = new int[N];
////////////
////////////    cout << sizeof(find)/sizeof(int) << endl;
////////////    // 0 : 등장안함,
////////////    // 1 : 등장
////////////    for (int i = 0;i < N;i++)
////////////        find[i] = 0;
////////////
////////////    for (int i = 0;i < s.size();i++)
////////////    {
////////////        //i부터~n까지의 sub
////////////        string substring = s.substr(i, N);
////////////        bool isValid = true;
////////////        int cnt = 0;
////////////        for (int j = 0;j < N;j++)
////////////        {
////////////            if (substring[j]-'0' > N)
////////////            {
////////////                break;
////////////                isValid = false;
////////////            }
////////////            if (find[substring[j]-'0'] == 0)
////////////            {
////////////                find[substring[j-'0']] = 1;
////////////                cnt++;
////////////            }
////////////            else
////////////            {
////////////                break;
////////////                isValid = false;
////////////            }
////////////        }
////////////        if (isValid&&cnt==N)
////////////        {
////////////            cout << stoi(substring) << endl;
////////////            list.push_back(stoi(substring));
////////////        }
////////////    }
////////////    if (!list.empty()) {
////////////        answer = *max_element(list.begin(), list.end());
////////////    }
////////////
////////////    return answer;
////////////}
////////////
////////////int main()
////////////{
////////////    solution({"1341232125"}, 2);
////////////    return 0;
////////////}
////////////
//////////////#include <string>
//////////////#include <vector>
//////////////
//////////////using namespace std;
//////////////
//////////////string getLongestString(const vector<string>& strings)
//////////////{
//////////////    string longestString = "";
//////////////    for (const string& str : strings)
//////////////    {
//////////////        if (str.length() > longestString.length())
//////////////            longestString = str;
//////////////    }
//////////////    return longestString;
//////////////}
//////////////
//////////////
//////////////
//////////////vector<string> solution(vector<string> merchantNames) {
//////////////    vector<string> answer;
//////////////
//////////////    string longestString = getLongestString(merchantNames);
//////////////
//////////////    if (!longestString.empty())
//////////////        answer.push_back(longestString);
//////////////
//////////////    return answer;
//////////////}
