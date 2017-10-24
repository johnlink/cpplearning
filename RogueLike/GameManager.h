#pragma once
#include <string>

#include "Player.h"
#include "Level.h"
#include "Enemy.h"

class GameManager
{
public:
	GameManager();
	
	void startGame();
	
	char getPlayerInput();

private:
	Player _player;
	Level _level;
};

