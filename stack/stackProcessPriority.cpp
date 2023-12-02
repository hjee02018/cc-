#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    // 프로세스no, 순위
    vector<pair<int, int>> q;
    for (int i = 0;i < priorities.size();i++)
        q.push_back({ i,priorities[i] });
    int cnt = 0;
    while (1)
    {
        // 현재 제일 앞 프로세스의 우선순위
        int cur = q[0].second;
        auto maxElement = max_element(q.begin(), q.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
            });
        // 있다면
        if (maxElement->second > cur)
        {
            int n = maxElement - q.begin();
            for(int i=0;i<n;i++)
            {
                pair<int, int> tmp = q[0];
                q.push_back(tmp);
                q.erase(q.begin());
            }
        }
        // 그리고 제일 앞에있는거 실행(cnt번째 실행)
        ++cnt;
        if (q[0].first == location)
            break;
        q.erase(q.begin());
    }
    return cnt;
}
