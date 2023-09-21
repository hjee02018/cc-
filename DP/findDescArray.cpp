// boj 11722
// DP

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	int A[1001];
	int dp[1001];
	int max = 0;

	cin >> N;
	for (int i = 1;i <= N;i++)
		cin >> A[i];

	for (int i = 1;i <= N;i++)
	{
		dp[i] = 1;
		for (int j = 1;j < i;j++)
		{
			if (a[i] < a[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i])
			max = dp[i];
	}
	cout << max << endl;
	return 0;
}