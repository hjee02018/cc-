// https://school.programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> stage_people;

int getSum(int i, int N)
{
    int sum = 0;
    // i�ܰ� �ʰ��� ��� ��
    for (int k = i;k <= N + 1;k++)
    {
        sum += stage_people[k];
    }
    return sum;
}

bool cmp(pair<int, double> a, pair<int, double> b)
{
    if (a.second > b.second)
        return true;
    else if (a.second < b.second)
        return false;
    else
    {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    // �ܰ躰, �ο���
    // 2,1,2,6,2,4,3,3
    // 2�ܰ� ������ : 2�ܰ� ������ ���/2�ܰ� ������ ���
    // 2�ܰ� ������ ��� : 2 �̻��� ���
    // 2�ܰ� ������ ��� : 2�� ���
    for (int i = 0;i < stages.size();i++)
        stage_people[stages[i]]++;
    // �ܰ躰 ������
    vector<pair<int, double>> stage_rate;
    for (int i = 1;i <= N + 1;i++)
    {
        double failrate = (double)stage_people[i] / (double)getSum(i, N);
        stage_rate.push_back({ i,failrate });
    }

    sort(stage_rate.begin(), stage_rate.end(), cmp);
    for (int i = 0;i < stage_rate.size();i++)
    {
        if(stage_rate[i].first!=N+1)
            answer.push_back(stage_rate[i].first);
    }
    
    return answer;
}


int main()
{
    solution(5,{2,1,2,6,2,4,3,3});
    return 0;
}