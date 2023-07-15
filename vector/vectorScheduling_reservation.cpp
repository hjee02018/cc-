#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
* 최소한의 객실 사용
* 퇴실 시간 + 10분 뒤부터 이용 가능
*/

bool isValid(vector<pair<int, int>> room,int start_time,int end_time)
{
    bool isValid = false;
    if (room[0].first >= end_time )
        isValid= true;
    for (int i = 1;i < room.size()-1;i++)
        if (room[i].second <= start_time && room[i+1].first >= end_time)
            isValid= true;
    if (room[room.size() - 1].second <= start_time)
        isValid= true;
    
    return isValid;
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 1;
    // room 종료 시간
    vector<vector<pair<int,int> >>room;
    string start1 = book_time[0].front();
    int start_time1 = stoi(start1.substr(0, 2)) * 60 + stoi(start1.substr(3, 2));
    string end1 = book_time[0].back();
    int end_time1 = stoi(end1.substr(0, 2)) * 60 + stoi(end1.substr(3, 2));

    room.push_back({ {start_time1,end_time1 + 10} });

    for (int i = 1;i < book_time.size();i++)
    {
        string start = book_time[i].front();
        string end = book_time[i].back();
        int start_time = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
        int end_time = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2))+10;
        bool add = true;
        for (int j = 0;j < room.size();j++)
        {
            if (isValid(room[j],start_time,end_time))
            {
                add = false;
                room[j].push_back({start_time,end_time});
                sort(room[j].begin(), room[j].end());
                break;
            }
        }
        if (add)
        {
            room.push_back({ {start_time,end_time} });
            answer++;
        }
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    solution({ {"15:00", "17:00"} ,{"16:40", "18:20" },{"18:20","18:30"},{"17:10","19:20"} ,{"18:30","21:20"}});
    return 0;
}