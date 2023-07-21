#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getVal(string mineral)
{
    if (mineral == "diamond")
        return 3;
    else if (mineral == "iron")
        return 2;
    else
        return 1;
}

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = 0;
    int dia = picks[0];
    int iron = picks[1];
    int stone = picks[2];
    
    // tot : ÃÑ °î±ªÀÌÀÇ ¼ö, tot_mineral : ÃÑ Ä¶ ¼ö ÀÖ´Â ±¤¹°ÀÇ ¼ö 
    int tot = dia + iron + stone;
    // Ä¶¼ö ÀÖ´Â°Å
    int tot_mineral = tot * 5;
    // Ä¶ °Å
    int tot_minerals = minerals.size();

    int real = min(tot_mineral, tot_minerals);

    vector <pair<int,int>> sum_of_val;
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
        sum_of_val.push_back({i,sum });
    }

    sort(sum_of_val.begin(), sum_of_val.end(),greater<>());


   
    return answer;
}



int main()
{
    solution({ 1,1,0 },{ "stone", "stone", "iron", "stone", "diamond", "diamond", "diamond", "diamond", "diamond", "diamond" });
    return 0;
}