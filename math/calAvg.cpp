#include<iostream>
#include <vector>
#include <iomanip> // 헤더 추가
using namespace std;
// 학번구간 [A,B] -> 학생들 성적의 평균 계산
int main(int argc, char** argv)
{
    int N,K;
    cin>>N>>K;
    vector<double> score;
    for(int i=0;i<N;i++)
    {
        double tmp;
        cin>>tmp;
        score.push_back(tmp);
    }
    for(int i=0;i<K;i++)
    {
        int s,e;
        cin>>s>>e;
        double sum=0;
        double range=e-s+1;
        // s~e까지의 평균
        for(int x=s-1;x<e;x++)
            sum+=score[x];
        cout<<fixed;
        cout.precision(2);
        cout<<sum/range<<endl;
    }
    
    return 0;
}
