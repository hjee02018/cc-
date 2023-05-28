#include<iostream>
using namespace std;
//https://softeer.ai/practice/info.do?idx=1&eid=414

int main(int argc, char** argv)
{
	int N, K;
	int res = 0;
	cin >> N >> K;
	string ph;
	cin >> ph;
	// H :ºÎÇ°, P: ·Îº¿
	for (int i = 0; i < N; i++)
	{
		if (ph[i] == 'P')
		{
			for (int j = i - K; j < i + K; j++)
			{
				if (i == j || j < 0 || j >= N)
					continue;
				if (ph[j] == 'H')
				{
					res++;
					ph[j] = 'X';
					ph[i] = 'O';
					break;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}