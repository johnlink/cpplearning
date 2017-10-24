#include "GameManager.h"

#include <string>
#include <iostream>
#include <conio.h>

GameManager::GameManager()
{
}

void GameManager::startGame()
{
	_player.init(1, 100, 10, 10, 0);
	_level.load("level1.txt", _player);
	
	bool isDone = false;
	while (!isDone)
	{
		_level.print();
		_level.movePlayer(getPlayerInput(), _player);

	}
}

char GameManager::getPlayerInput()
{
	char input;

	bool validInput = false;
	while(!validInput)
	{
		std::cout << "Enter a move command (w/a/s/d): ";
		input = _getch();

		switch (input)
		{
		case 'w':
		case 'W':
		case 'a':
		case 'A':
		case 's':
		case 'S':
		case 'd':
		case 'D':
			validInput = true;
			break;
		default:
			std::cout << "*** INVALID INPUT ***\n";
		}
	}

	return input;
	
}