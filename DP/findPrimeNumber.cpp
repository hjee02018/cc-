//https://school.programmers.co.kr/learn/courses/30/lessons/42839
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

// 제곱수 고려할 것
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2;i < n;i++)
        if (n % i == 0)
            return false;
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    map<int, int>mp;
    vector<int> no;
    for (int i = 0;i < numbers.length();i++)
        no.push_back(numbers[i] - '0');

    //sort(numbers.begin(), numbers.end());

    do
    {
        string tmp;
        cout << numbers << endl;
        // 가능한 문자열 길이 ( 1~numbers.size())
        for (int i = 0;i < numbers.size();i++)
        {
            tmp += numbers[i];
            if (isPrime(stoi(tmp)))
                mp[stoi(tmp)]++;
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    cout << mp.size() << endl;
    return mp.size();
}



int main()
{
    solution("1231");
    return 0;
}
