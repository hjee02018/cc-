#include<iostream>

#include <cmath> //C++
using namespace std;

int main4(int argc, char** argv)
{
	int N;
	int res = 4;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		int count = 0;
		// �簢���� ����  = 4^(N-1)
		// 0 : 0 ��  = 4
		// 1�ܰ� : 1��  (4+1) x 1 - 0 = 5 => 9
		// 2�ܰ� : 4�� (4+1) x 4 - 4 = 16 => 25
		// 3�ܰ� : 16�� (4+1)x16 - 16 = 64 => 89
		int square = pow(4, i - 1);
		if (square == 1)
			count = 5 * square;
		else
			count = (5 * square) - 4 * square;
		res += count;
	}
	cout << res << endl;
	return 0;
}