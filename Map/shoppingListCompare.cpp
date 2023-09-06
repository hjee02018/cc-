// https://school.programmers.co.kr/learn/courses/30/lessons/131127

#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* want[i] 를 number[i]개 사야함
* 1일에 1개 구매
* 1일에 1개 할인
* 10일동안 사야함
*/


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> shopping;
    
    // 총 사야하는 물건의 개수
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