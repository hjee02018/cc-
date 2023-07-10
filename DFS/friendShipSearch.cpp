#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
* 새로운 친구 : 10원
* 원래 친구 : 5원
* 최대 단계 만큼을 친구로 인정, 
*/

// 친구 목록
vector<int> friends;
// 친구가 아닌 관계들
vector<vector<int>> relations;


int solution(vector<vector<int>> relationships, int target, int limit) 
{
    int answer = 0;
    // 1단계 친구 찾기
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

    // ~limit 단계 친구 찾기
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

    cout << "원래 알던 친구" << old << endl;
    cout << "새로운 친구" << newcnt << endl;
    
    answer = newcnt + 5 * old + 10 * newcnt;
    return answer;
}

int main()
{
    int res= solution({ {1,2},{2,3} ,{2,6},{3,4},{4,5} }, 2, 3);
    cout << res << endl;
    return 0;
}
