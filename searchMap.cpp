#include<iostream>
using namespace std;


void Sread(int i, int j)
{
	// (i,j)�� �ҳ��Ⱑ �� �и��� ��,��,��,�� Ȯ��
}

int main(int argc, char** argv)
{
	int R, C;
	int res = 0;
	cin >> R >> C;
	// R��C���� ���� 
	// ���� : . �ҳ��� : *. �� : X
	// W=>H(������to��)
	char map[50][50];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	// �źи��� ��,��,��,�� & �ҳ���� �źи��� ��,��,��,�� Ȯ��
	// �ҳ���� ���� ���� �� X
	for (int i = 0; i < R; i++)
	{
		
	}

	return 0;
}