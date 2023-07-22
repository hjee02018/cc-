#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int getVal(string mineral)
{
    if (mineral == "diamond")
        return 25;
    else if (mineral == "iron")
        return 5;
    else
        return 1;
}

int countVal(string pick, string mineral)
{
    if (pick == "dia")
        return 1;
    else if (pick == "iron")
    {
        if (mineral == "diamond")
            return 5;
        else
            return 1;
    }
    else
    {
        if (mineral == "diamond")
            return 25;
        else if (mineral == "iron")
            return 5;
        else
            return 1;
    }
}

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = 0;
    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    stack<string> tool;
    vector<string>minerals2;
    
    // tot : ÃÑ °î±ªÀÌÀÇ ¼ö, tot_mineral : ÃÑ Ä¶ ¼ö ÀÖ´Â ±¤¹°ÀÇ ¼ö 
    int tot = dia + iron + stone;

    for (int i = 0;i < stone;i++)
        tool.push("stone");
    for (int i = 0;i < iron;i++)
        tool.push("iron");
    for (int i = 0;i < dia;i++)
        tool.push("dia");

    // Ä¶¼ö ÀÖ´Â°Å
    int tot_mineral = tot * 5;
    // Ä¶ °Å
    int tot_minerals = minerals.size();

    int real = min(tot_mineral, tot_minerals);

    if (tot_minerals > tot_mineral)
    {
        for (int i = 0;i < tot_minerals;i++)
        {
            minerals2.push_back(minerals[i]);
        }
        minerals = minerals2;
    }

    vector <pair<int,int>> sum_of_val;
    bool isFit = true;
    for (int i = 0;i < real;i+=5)
    {
        int sum = 0;
        int j;
        for (j = 0;j < 5;j++)
        {
            if (i+j >= real)
                break;
            sum += getVal(minerals[i + j]);
        }
        sum_of_val.push_back({sum,i });
    }

    sort(sum_of_val.begin(), sum_of_val.end(),greater<>());

    for (int i = 0;i < sum_of_val.size();i++)
    {
        int idx = sum_of_val[i].second;
        string pick = tool.top();
        tool.pop();
        if (idx + 5 < minerals.size())
        {
            for (int j = idx;j < idx + 5;j++)
            {
                answer += countVal(pick, minerals[j]);
            }
        }
        else
        {
            for (int j = idx;j < minerals.size();j++)
                answer += countVal(pick, minerals[j]);
        }
    }

    cout << answer << endl;
    return answer;
}



int main()
{
    solution({1,0,1},{ "iron", "iron", "iron", "iron", "diamond", "diamond", "diamond" });
    //solution({ 1,1,0 },{ "stone", "stone", "iron", "stone", "diamond", "diamond", "diamond", "diamond", "diamond", "diamond" });
    return 0;
}