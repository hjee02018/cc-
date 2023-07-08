// https://school.programmers.co.kr/learn/courses/30/lessons/160586

#include <string>
#include <vector>
#include <iostream>

using namespace std;


int count(vector<string> keymap, char key)
{
    int no = 1001;
    for (int i = 0;i < keymap.size();i++)
    {
        if(keymap[i].find_first_of(key) != string::npos)
			if (no > keymap[i].find_first_of(key))
				no = keymap[i].find_first_of(key);
    }
    if (no == 1001)
        return -1;
    return no+1;
}


vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    vector<int> answer;

    for (int i = 0;i < targets.size();i++)
    {
        int sum = 0;
        string target = targets[i];

        // target(문자열)을 누르기 위한 keymap 탐색
        for (int j = 0;j < target.size();j++)
        {
            if (count(keymap, target[j]) == -1)
            {
                sum = -1;
                break;
            }
            sum += count(keymap, target[j]);
        }
        cout << sum << endl;
        answer.push_back(sum);
    }

    return answer;
}



int main2()
{
    solution({ "ABACD", "BCEFD" }, { "ABCD","AABB" });
    return 0;
}