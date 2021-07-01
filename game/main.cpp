#include "Player.h"
#include "wordGame.h"
#include <iostream>
using namespace std;

int main()
{
	int playernum=0;
	cout << "끝말 잇기 게임을 시작합니다" << endl;
	cout << "게임 참가하는 인원은 몇명입니까?";
	cin >> playernum;
	/*참가인원수를 입력받음*/

	wordGame hjgame(playernum);
	wordGame* game = &hjgame;
	game->startGame();
	game->Gaming();	
}
