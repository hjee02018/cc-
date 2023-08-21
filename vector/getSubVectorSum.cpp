#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int solution(vector<int> elements) 
{
    int answer = 0;
    int type = elements.size();
    vector<int> ans;
	vector<int> elements_twice;
	elements_twice = elements;
	for (int i = 0;i < type;i++)
	{
		elements_twice.push_back(elements[i]);
	}

    int idx = 0;
    while (type > 0)
    {
        if (idx == elements.size()-1)
        {
            idx = 0;
            type--;
            continue;
        }

        // type개씩 slice
		vector<int> slice(elements_twice.begin() + idx, elements_twice.begin() + idx+type);
        int sum = accumulate(slice.begin(), slice.end(),0);
		auto it = find(ans.begin(), ans.end(), sum);
        idx++;
		if (it == ans.end())
		{
			ans.push_back(sum);
			answer++;
		}
		else
			continue;
    }
   

   
    return answer;
}

int main() {
    solution({ 7,9,1,1,4 });
}

//int type = elements.size();
   //vector<int> elements_twice;
   //elements_twice = elements;
   //for (int i = 0;i < type;i++)
   //{
   //    elements_twice.push_back(elements[i]);
   //}

   //vector<int> ans;
   // 1~type개 로 구성된 수열의 부분합 개수 구하기


   //for (int i = 1;i < type+1;i++)
   //{
   //    for (int j = 0;j < type;j++)
   //    {
   //        int sum = 0;
   //        
   //        // ver2
   //        //int start = j;
   //        //int end = j + num;

   //        //vector<int> slice(elements_twice.begin() + start, elements_twice.begin() + end );
   //        //sum = accumulate(slice.begin(), slice.end(), 0);

   //        // ver1
   // //       for (int k = j;k < j + num;k++)
   // //       {
   // //           if (k >= type)
   // //               sum += elements[k - type];
   // //           else
               //	//sum += elements[k];
   // //       }

   //        auto it = find(ans.begin(), ans.end(), sum);
   //        if (it == ans.end())
   //        {
   //            ans.push_back(sum);
   //            answer++;
   //        }
   //        else
   //            continue;
   //    }
   //}
