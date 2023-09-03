// https://school.programmers.co.kr/learn/courses/30/lessons/131704��

#include <string>
#include <vector>
#include <stack>

using namespace std;

// order : ���ϴ� ���� ����, answer : �� ���� ���ڸ� ���� �� �ִ���  
int solution(vector<int> order) 
{
    int answer = 0;
    stack<int> mystack;
    
    int idx = 1;
    for (int i = 0;i < order.size();i++)
    {
        // n��°�� n�� ����
        if (order[i] == idx)
        {
            answer++;
            idx++;
        }
        // 1��°�� 5�� ���ڸ� -> mystack�� ���ʷ� ����
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
        // 3��°�� 1�� ���ڸ� -> mystack������
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