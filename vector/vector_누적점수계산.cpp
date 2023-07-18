// https://school.programmers.co.kr/learn/courses/30/lessons/118666
#include <string>
#include <vector>

#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    map<string, int> res;

    for (int i = 0;i < choices.size();i++)
    {
        string first = survey[i].substr(0, 1);
        string sec = survey[i].substr(1, 1);
        int ans = choices[i];
        if (ans < 4)
            res[first] += (3-ans+1);
        else if (ans > 4)
            res[sec] += (ans-4);
        else
            continue;
    }

    if (res["R"] < res["T"])
        answer += "T";
    else
        answer += "R";


    if (res["C"] < res["F"])
        answer += "F";
    else
        answer += "C";


    if (res["J"] < res["M"])
        answer += "M";
    else
        answer += "J";

    if (res["A"] < res["N"])
        answer += "N";
    else
        answer += "A";


    return answer;
}