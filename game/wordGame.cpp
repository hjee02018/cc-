#include "wordGame.h"

wordGame::wordGame(int num)
{
	nPlayers = num;
}
/*동적할당되는 포인터 멤버가 있으므로 생성자 명시*/



void  wordGame::startGame()
{
	createPlayers();
}



wordGame::~wordGame()
{
	delete players;
}


void wordGame::createPlayers()
{
	players = new Player[nPlayers];
	/*player는 참가자들Player객체들을 가르키는 포인터*/

	string playerName;
	for (int i = 0;i < nPlayers;++i)
	{
		cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
		cin >> playerName;
		players[i].setName(playerName);
	}
}

void wordGame::Gaming()
{

	int k = nPlayers;
	int i = 0;

	cout << "시작하는 단어는" << startName << "입니다" << endl;

	for (;;)
		/*무한루프*/
	{
		string b;
		cout << players[i % k].getName() << ">>";
		cin >> b;
		int j = startName.size();
		if (startName.at(j - 2) == b.at(0) && startName.at(j - 1) == b.at(1))
		{
			startName = b;
			/*문자열 startName 에 문자열 b를 대입(복사)*/
		}
		else
		{
			cout << players[i % k].getName() << "탈락입니다" << endl;
			break;
		}
		/*탈락이면 무한루프 탈출*/
		++i;
	}
}
