#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long calculate(long long a, long long b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        return a * b;
}
long long solution(string expression)
{
    long long answer = 0;
    vector<long long> no;
    vector<char> op;

    string n = "";
    for (int i = 0;i < expression.length();i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            op.push_back(expression[i]);
            no.push_back(stoi(n));
            n = "";
        }
        else
        {
            n += expression[i];
        }
    }
    no.push_back(stoi(n));
    for (int i = 0;i < no.size();i++)
    {
        if (i != 0)
        {
            cout << op[i - 1] << no[i];
        }
        else
            cout << no[i];
    }
    // 연산자별 순위 순회 
    vector<int> p{ 0,1,2 };
    vector<int> ans;
    string str_operator = "*+-";
    vector<long long> tmp_no;
    vector<char> tmp_op;
    do
    {
        // op와 no가 비워짐
        tmp_no = no;
        tmp_op = op;
        // 
        // 연산자 높은 것부터
        for (int i = 0;i < p.size();i++)
        {
            // 연산
            for (int j = 0;j < tmp_op.size();)
            {
                if (str_operator[p[i]] == tmp_op[j])
                {
                    // 숫자1 연산자 숫자2 : 삭제
                    long long res = calculate(tmp_no[j], tmp_no[j + 1], tmp_op[j]);
                    tmp_no.erase(tmp_no.begin() + j);
                    tmp_no.erase(tmp_no.begin() + j);
                    tmp_op.erase(tmp_op.begin() + j);
                    // 계산 결과 : 삽입
                    tmp_no.insert(tmp_no.begin() + j, res);
                }
                else
                    j++;
            }
        }
        ans.push_back(abs(tmp_no[tmp_no.size() - 1]));
    } while (next_permutation(p.begin(), p.end()));

    sort(ans.begin(), ans.end(),greater<int>());
    return ans[0];

    //// next_permutation 사용
    //vector<int> np{ 1,2,3 };
    //sort(np.begin(), np.end());
    //do
    //{
    //    for (auto it = np.begin();it != np.end();it++)
    //        cout << *it << " ";
    //    cout << endl;
    //} while (next_permutation(np.begin(), np.end()));

}

int main()
{
    //solution("100-200*300-500+20");
    solution("200-300-500-600*40+500+500");
    return 0;
}