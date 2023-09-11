#include <string>
#include <vector>

using namespace std;

/*
- A를 모두 나누고 B를 전부 나눌 수 없거나
- B를 모두 나누고 A를 전부 나눌 수 없는 양의 정수
*/

// array의 최대공약수 구하기
int GCD(int a, int b)
{
	int tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int getGCD(vector<int> array)
{
	if (array.size() == 1)
		return array[0];
	else
	{
		int gcd = GCD(array[0], array[1]);
		for (int i = 2;i < array.size()-1;i++)
		{
			gcd = GCD(gcd, array[i]);
		}
		return gcd;
	}
}

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int getLCM(vector<int> array)
{
	if (array.size() == 1)
		return array[0];
	else
	{
		int lcm = LCM(array[0],array[1]);
		for (int i = 2;i < array.size() - 1;i++)
		{
			lcm = LCM(array[i], array[i]);
		}
		return lcm;
	}
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
	int answer = 0;
	int aGCD = getGCD(arrayA);
	int bGCD = getGCD(arrayB);
	int aLCM = getLCM(arrayA);
	int bLCM = getLCM(arrayB);

	vector<int> a;
	vector<int> b;

	for (int i = 1;i <= aGCD;i++)
		if (aGCD % i == 0)
			a.push_back(i);
	for (int i = 1;i <= bGCD;i++)
		if (bGCD % i == 0)
			b.push_back(i);

	int c1 = 0;
	for (int i = a.size() - 1;i >= 0;i--)
	{
		bool isValid = true;
		int tmp = a[i];
		for (int j = 0;j < arrayB.size();j++)
		{
			if (arrayB[j] % tmp == 0)
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
			break;
		else
		{
			c1 = tmp;
			break;
		}
	}
	int c2 = 0;
	// b를 나눠떨어지게 하는 것들 중에
	for (int i = b.size() - 1;i >= 0;i--)
	{
		bool isValid = true;
		int tmp = b[i];
		for (int j = 0;j < arrayA.size();j++)
		{
			// a를 나눈다면
			if (arrayA[j] % tmp == 0)
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
			break;
		else
		{
			c2 = tmp;
			break;
		}
	}


	if (c1 >= c2)
		return c1;
	else
		return c2;

}