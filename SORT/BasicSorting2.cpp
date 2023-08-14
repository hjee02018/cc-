#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int col_val;

bool compare(vector<int> data1, vector<int> data2)
{
    if (data1[col_val] == data2[col_val])
        return data1[0] > data2[0];
    else
        return (data1[col_val] < data2[col_val]);
}



int solution(vector<vector<int>> data, int col, int row_begin, int row_end) 
{
    int answer = 0;
    vector<int> res;
    col_val = col-1;

    // col번 째 값을 기준으로 내림차순
    // 1번째 열(기본키) 기준으로 오름차순
    sort(data.begin(), data.end(), compare);
    
    int idx = 0;
    for (int i = row_begin-1;i < row_end;i++) 
    {
        int sum = 0;
        for (int j = 0;j < data[i].size();j++)
        {
            sum += data[i][j] % (i + 1);
        }
        res.push_back(sum);
        idx++;
    }
    for (int i = 0;i < res.size();i++)
    {
        answer ^= res[i];
    }

    return answer;
}

int main()
{
    solution({ {2,2,6},{1,5,10},{4,2,9},{3,8,3} }, 2, 2, 3);
}