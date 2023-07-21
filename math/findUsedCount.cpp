#include <string>
#include <vector>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) 
{
    int answer = 0;
    
    int dia, iron, stone;
    dia = picks[0];
    iron = picks[1];
    stone= picks[2];

    int idx = 0;

    while (dia-- && idx < minerals.size())
    {
        for (int i = 0;i < 5;i++)
        {
            if (idx >= minerals.size())
                break;
            answer++;
            idx++;
        }
    }
    
    while (iron-- && idx < minerals.size())
    {
        for (int i = 0;i < 5;i++)
        {
            if (idx >= minerals.size())
                break;
            string mineral = minerals[idx];
            if (mineral == "diamond")
            {
                answer += 5;
            }
            else
                answer++;

            idx++;
        }
    }

    while (stone-- && idx < minerals.size())
    {
        for (int i = 0;i < 5;i++)
        {
            if (idx >= minerals.size())
                break;
            string mineral = minerals[idx];
            if (mineral == "diamond")
                answer += 25;
            else if (mineral == "iron")
                answer += 5;
            else
                answer++;
            idx++;
        }
    }

    return answer;
}

int main()
{
    solution({ 1,3,2 },{ "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });
    return 0;
}