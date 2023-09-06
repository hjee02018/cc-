// https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* want[i] �� number[i]�� �����
* 1�Ͽ� 1�� ����
* 1�Ͽ� 1�� ����
* 10�ϵ��� �����
*/


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> shopping;
    
    // �� ����ϴ� ������ ����
    int tot = 0;

    for (int i = 0;i < want.size();i++)
        shopping[want[i]] += number[i];


    for (int i = 0;i < discount.size();i++)
    {
        map<string, int> tmp;

        for (int idx = i;(idx < i + 10 && idx<discount.size());idx++)
            tmp[discount[idx]]++;

        bool isEqual = (tmp == shopping);
        if (isEqual)
            answer++;
    }

    return answer;
}

int main() {
    solution({ "banana", "apple", "rice", "pork", "pot" },{3,2,2,2,1},{ "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });
    return 0;
}