# cc-
algorithm using c and c++

#include <iostream>
#include <fstream>
using namespace std;
int min(int a, int b, int c)
{
	if (a <= b)
	{
		if (a < c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b <= c)
		{
			return b;
		}
		else return c;
	}
}
int max(int a, int b)
{
	if (a >= b)
		return a;
	else return b;
}
void align(int m, int n, char* x, char* y, int** M, int** P)
{
	int i = m - 1;
	int j = n - 1;
	int p = max(m, n);
	int* new_x = new int[p];
	int* new_y = new int[p];
	for (int a = 0;a < p;a++)
	{
		new_x[a] = 0;
	}
	for (int b = 0;b < p;b++)
	{
		new_y[b] = 0;
	}

	for (int k = p;k > 0;k--)
	{
		switch (P[i][j])
		{
		case 1:
			i--;j--;
			break;
		case 2:
			i--;
			new_y[k-1] = 1;
			break;
		case 3:
			j--;
			new_x[k-1] = 1;
			break;
		}
	}

	int index_x = 0;
	int index_y = 0;
	for (int k = 0;k < p;k++)
	{
		if (new_x[k] == 1)
		{
			cout << "-";
		}
		else
		{
			cout << x[index_x];
			index_x++;
		}
	}
	cout << endl;
	for (int k = 0;k < p;k++)
	{
		if (new_y[k] == 1)
		{
			cout << "-";
		}
		else
		{
			cout << y[index_y];
			index_y++;
		}
	}
	cout << endl;
}

void opt(int m, int n, char* x, char* y, int** M,int**P)
// optimal alignment 를 찾는 func
{
	int penalty = 0;

	for (int i = 0;i <= m;i++)
		M[i][0] = 3* i;
	for(int j=0;j<=n;j++)
		M[0][j] = 3 * j;
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			
			if (x[i-1] == y[j-1]) penalty = 0;
			else penalty = 2;
			M[i][j] = min(M[i - 1][j - 1] + penalty, M[i - 1][j] + 3, M[i][j - 1] + 3);

			
			if (M[i][j] == M[i - 1][j - 1] + penalty) P[i - 1][j - 1] = 1;//case 1
			else if (M[i][j] == M[i - 1][j] + 3)P[i - 1][j - 1] = 2;//case 2
			else if (M[i][j]==M[i][j-1]+3 ) P[i - 1][j - 1] = 3;
			//else if (M[i][j] == M[i][j - 1] + 3)P[i-1][j-1] = 3;//case 3l

		}
	}
	align(m, n,x, y,M,P);
	// align 에서 M[m+1][n+1]의 값을 바탕으로 optimal alignment결과에 해당하는 sequence를 출력

	for (int i = 0;i < m + 1;i++)
	{
		for (int j = 0;j < n + 1;j++)
		{
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout<<P[i][j]<<" ";
		}
		cout << endl;
	}
}

int main(int argc,char*argv[])
{
	freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	// N : test case의 개수
	{
		int m;
		int n;
		cin >> m;
		char* x = new char[m];
		for (int i = 0;i < m;i++)
		{
			cin >> x[i];
		}
		cin >> n;
		char* y = new char[n];
		for (int j = 0;j < n;j++)
		{
			cin >> y[j];
		}
		// sequence x와 y & x와 y의 길이를 입력받음.
		
		// M(i,j)를 저장할 다차원배열이 필요..
		int** M;
		M = new int* [m+1];
		for (int i = 0;i < m+1;i++)
		{
			M[i] = new int[n+1];
		}
		int** P;
		P = new int* [m];
		for (int i = 0;i < m;i++)
		{
			P[i] = new int[n];
		}
		opt(m, n, x, y, M,P);
		// optimal alignment를 구하는 함수호출 및 배열
		
	}
}




