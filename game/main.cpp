#include "Player.h"
#include "wordGame.h"
#include <iostream>
using namespace std;

int main()
{
	int playernum=0;
	cout << "���� �ձ� ������ �����մϴ�" << endl;
	cout << "���� �����ϴ� �ο��� ����Դϱ�?";
	cin >> playernum;
	/*�����ο����� �Է¹���*/

	wordGame hjgame(playernum);
	wordGame* game = &hjgame;
	game->startGame();
	game->Gaming();	
}
