#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0;i < arr.size();i++)
    {
        int j;
        for ( j = i+1;j<arr.size();j++)
        {
            if (arr[j] == arr[i])
                continue;
            else
                break;
        }
        answer.push_back(arr[i]);
        if(j!=i)
			i = j-1;
    }

    cout << "Hello Cpp" << endl;

    return answer;
}
int main()
{
    solution({1,1,3,3,0,1,1});
    return 0;
}
