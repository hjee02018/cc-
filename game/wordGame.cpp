#include "wordGame.h"

wordGame::wordGame(int num)
{
	nPlayers = num;
}
/*�����Ҵ�Ǵ� ������ ����� �����Ƿ� ������ ���*/



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
	/*player�� �����ڵ�Player��ü���� ����Ű�� ������*/

	string playerName;
	for (int i = 0;i < nPlayers;++i)
	{
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
		cin >> playerName;
		players[i].setName(playerName);
	}
}

void wordGame::Gaming()
{

	int k = nPlayers;
	int i = 0;

	cout << "�����ϴ� �ܾ��" << startName << "�Դϴ�" << endl;

	for (;;)
		/*���ѷ���*/
	{
		string b;
		cout << players[i % k].getName() << ">>";
		cin >> b;
		int j = startName.size();
		if (startName.at(j - 2) == b.at(0) && startName.at(j - 1) == b.at(1))
		{
			startName = b;
			/*���ڿ� startName �� ���ڿ� b�� ����(����)*/
		}
		else
		{
			cout << players[i % k].getName() << "Ż���Դϴ�" << endl;
			break;
		}
		/*Ż���̸� ���ѷ��� Ż��*/
		++i;
	}
}
