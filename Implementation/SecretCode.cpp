#include<iostream>
#include <vector>
using namespace std;

int main3(int argc, char** argv)
{
	int M, N, K;
	cin >> M >> N >> K;
	vector<int> secret(M, 0);
	vector<int> input(N, 0);
	for (int i = 0; i < M; i++)
		cin >> secret[i];
	for (int i = 0; i < N; i++)
		cin >> input[i];

	if (N < M)
		cout << "normal" << endl;
	else
	{
		bool isValid = false;
		for (int i = 0; i < N; i++)
		{
			if (input[i] == secret[0])
			{
				isValid = true;
				int k = 0;
				for (int j = i; j < i + M; j++, k++)
				{
					if (input[j] == secret[k])
						isValid = true;
					else
					{
						isValid = false;
						break;
					}
				}
				if (isValid)
				{
					cout << "secret" << endl;
					break;
				}
			}
		}
		if (!isValid)
			cout << "normal" << endl;
	}

	return 0;
}