#pragma once
#include "GameBoard.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Start();

	int GetXInput();
	int GetYInput();

private:
	char _player1 = 'X';
	char _player2 = 'O';

	char _currentPlayer;

	GameBoard _gameBoard;

	bool placeMarker(int x, int y);

};

