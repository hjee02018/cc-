//// https://school.programmers.co.kr/learn/courses/30/lessons/155651

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int>p2)
{
    return p1.first < p2.first;
}
bool isValid(vector<pair<int,int>>room,pair<int,int> p)
{
    if (room[0].first >= p.second + 10)
        return true;
    if (room[room.size() - 1].second <= p.first)
        return true;

    for (int i = 0;i < room.size()-1;i++)
    {
        if (room[i].second <= p.first && p.second + 10 <= room[i + 1].first)
            return true;
    }
    return false;
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    // cnt : 예약 건수
    int cnt = book_time.size();
    vector<pair<int, int>> booking;
    vector<vector<pair<int, int>>>room;

    for (int i = 0;i < cnt;i++)
    {
        vector<string> book = book_time[i];
        string start = book[0];
        string end = book[1];
        int start_time = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
        int end_time = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));
        booking.push_back({ start_time,end_time });
    }
    sort(booking.begin(), booking.end(),compare);
    for (int i = 0;i < cnt;i++)
    {
        pair<int, int>res;
        res.first= booking[i].first;
        res.second = booking[i].second + 10;
        if (room.empty())
        {
            // 방만들기
            vector<pair<int, int>> new_room;
            new_room.push_back(res);
            room.push_back(new_room);
            answer++;
        }
        else
        {
            bool isLeft = false;
            for (int j = 0;j < room.size();j++)
            {
                if (isValid(room[j],res))
                {
                    isLeft = true;
                    room[j].push_back(res);
                    sort(room[j].begin(), room[j].end(), compare);
                    break;
                }
            }
            // 방만들기
            if (!isLeft)
            {
                vector<pair<int, int>> new_room;
                new_room.push_back(res);
                room.push_back(new_room);
                answer++;
            }
        }
    }

    return answer;
}