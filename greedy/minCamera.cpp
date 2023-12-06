#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int>&b)
{
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    // 진출지점 기준 오름차순
    // [[-20,-15], [-18,-13], [-14,-5], [-5,-3]]
    sort(routes.begin(),routes.end(),cmp);
    // 설치된 위치
    answer++;
    int cur=routes[0][1];
    for(int i=1;i<routes.size();i++)
    {
        // 다음 차량의 진입이 이전 차량의 진출(cur)보다 크다면 -> 카메라 추가
        if(routes[i][0]<=cur)
            continue;
        else
        {
            cur=routes[i][1];
            answer++;
        }
    }
    
    return answer;
}
