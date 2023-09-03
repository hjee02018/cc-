// https://school.programmers.co.kr/learn/courses/30/lessons/131704ㄴ

#include <string>
#include <vector>
#include <stack>

using namespace std;

// order : 원하는 상자 순서, answer : 몇 개의 상자를 실을 수 있는지  
int solution(vector<int> order) 
{
    int answer = 0;
    stack<int> mystack;
    
    int idx = 1;
    for (int i = 0;i < order.size();i++)
    {
        // n번째에 n번 상자
        if (order[i] == idx)
        {
            answer++;
            idx++;
        }
        // 1번째에 5번 상자를 -> mystack에 차례로 저장
        else if (order[i] > idx)
        {
            while (order[i] > idx)
            {
                mystack.push(idx);
                idx++;
            }
            if (order[i] == idx)
            {
                answer++;
                idx++;
            }
        }
        // 3번째에 1번 상자를 -> mystack뒤지기
        else
        {
            if (mystack.top() == order[i])
            {
                answer++;
                mystack.pop();
            }
            else
            {
                break;
            }
        }
    }


    return answer;
}

int main()
{
    solution({3,5,2,4,1 });
    return 0;
}