#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) 
{
    int answer = 0;
    int isValid = false;
    int len = topping.size();
    int left = 1;
    int right = len - left;

    map<int, int> m_left;
    map<int, int> m_right;

    m_left[topping[0]]++;
    
    for (int i = 1;i < len;i++)
        m_right[topping[i]]++;

    while (left < len)
    {
        right = len - left;
        
        m_left[topping[left]]++;
        if (--m_right[topping[left]] == 0)
            m_right.erase(topping[left]);
        
        if (m_left.size() == m_right.size())
        {
            isValid = true;
            answer++;
        }
        // 좌방향으로(즉 left원소를 늘려가는 과정이므로)
        else if (m_left.size() > m_right.size())
        {
            break;
        }
        left++;
    }

    if (!isValid)
        return 0;
    else
        return answer;
}

int main() {
    solution({1,2,1,3,1,4,1,2});
}