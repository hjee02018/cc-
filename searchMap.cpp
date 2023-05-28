#include<iostream>
using namespace std;


void Sread(int i, int j)
{
	// (i,j)의 소나기가 매 분마다 상,하,좌,우 확산
}

int main(int argc, char** argv)
{
	int R, C;
	int res = 0;
	cin >> R >> C;
	// R행C열의 지도 
	// 공란 : . 소나기 : *. 강 : X
	// W=>H(세차장to집)
	char map[50][50];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	// 매분마다 상,하,좌,우 & 소나기는 매분마다 상,하,좌,우 확산
	// 소나기와 강은 지날 수 X
	for (int i = 0; i < R; i++)
	{
		
	}

	return 0;
}