#pragma once
#include "Player.h"

class wordGame
{
private:

	string startName = "¾Æ¹öÁö";
	int nPlayers=0;
	Player* players;
	void createPlayers();
public:
	wordGame(int num);
	~wordGame();
	void  startGame();
	void Gaming();
};

