#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) 
{
    string answer = "";
    vector<int> x;
    vector<int> y;

    for (int i = 0;i < X.length();i++)
        x.push_back(X[i]);
    for (int i = 0;i < Y.length();i++)
        y.push_back(Y[i]);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    bool isValid = false;
    while (!x.empty() && !y.empty())
    {
        if (x.back() == y.back())
        {
            if (x.back() != '0')
                isValid = true;
            answer += x.back();
            x.pop_back();
            y.pop_back();
        }
        else if (x.back()>y.back())
            x.pop_back();
        else
            y.pop_back();
    }
    if (answer.size() == 0)
        return "-1";
    if (answer.size()!=0 && !isValid)
        return "0";

    return answer;
}
int main()
{
    solution("100","2345");
    return 0;
}
