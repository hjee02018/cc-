#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution_findBoxPrice(int k, int m, vector<int> score) 
{
    int answer = 0;
    int cnt = score.size() / m;

    if (cnt == 0)
        return 0;

    sort(score.begin(), score.end(), greater<>());

    int idx = m-1;
    for (int i = 0;i < cnt;i++)
    {
        answer += score[idx] * m;
        cout << score[idx];
        idx += m;
    }
    
    return answer;
}