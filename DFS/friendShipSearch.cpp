#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
* ���ο� ģ�� : 10��
* ���� ģ�� : 5��
* �ִ� �ܰ� ��ŭ�� ģ���� ����, 
*/

// ģ�� ���
vector<int> friends;
// ģ���� �ƴ� �����
vector<vector<int>> relations;


int solution(vector<vector<int>> relationships, int target, int limit) 
{
    int answer = 0;
    // 1�ܰ� ģ�� ã��
    for (int i = 0;i < relationships.size();i++)
    {
        vector<int> relation = relationships[i];
        if (relation.front() == target)
            friends.push_back(relation.back());
        else if (relation.back() == target)
            friends.push_back(relation.front());
        else
            relations.push_back(relation);
    }
    int old = friends.size();

    // ~limit �ܰ� ģ�� ã��
    limit -= 1;
    while (limit-- > 0)
    {
        cout << "limit : " << limit << endl;
        vector<vector<int>> tmp;
        vector<int> tmp2;
        for (int i = 0;i < relations.size();i++)
        {
            vector<int> relation = relations[i];
            int p1 = relation.front();
            int p2 = relation.back();
            bool isFriend = false;
            for (int j = 0;j < friends.size();j++)
            {
                if (p1 == friends[j])
                {
                    isFriend = true;
                    tmp2.push_back(p2);
                    break;
                }
                else if (p2 == friends[j])
                {
                    isFriend = true;
                    tmp2.push_back(p1);
                    break;
                }
            }
            if(isFriend==false)
                tmp.push_back(relations[i]);
        }
        for (int k = 0;k < tmp2.size();k++)
            friends.push_back(tmp2[k]);

        relations = tmp;
    }
    int newcnt = friends.size() - old;

    cout << "���� �˴� ģ��" << old << endl;
    cout << "���ο� ģ��" << newcnt << endl;
    
    answer = newcnt + 5 * old + 10 * newcnt;
    return answer;
}

int main()
{
    int res= solution({ {1,2},{2,3} ,{2,6},{3,4},{4,5} }, 2, 3);
    cout << res << endl;
    return 0;
}
