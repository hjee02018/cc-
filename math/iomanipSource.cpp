#include<iostream>

#include <iomanip> // for std::setprecision

using namespace std;

int main(int argc, char** argv)
{
	int N, K;
	int* score;
	cin >> N >> K;
	score = new int[N];
	for (int i = 0;i < N;i++)
	{
		int tmp;
		cin >> tmp;
		score[i] = tmp;
	}
	for (int i = 0;i < K;i++)
	{
		int start, end,sum=0;
		cin >> start >> end;
		for (int j = start-1;j < end;j++)
		{
			sum += score[j];
		}
		cout << fixed << setprecision(2) << static_cast<double>(sum) / (end - start + 1) << endl;
		//cout << sum / (end - start + 1) << endl;
	}
	delete[] score;
	return 0;
}