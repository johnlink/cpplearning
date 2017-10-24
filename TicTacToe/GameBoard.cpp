#include <iostream>

#include "GameBoard.h"

GameBoard::GameBoard()
{
	ClearBoard();
}


GameBoard::~GameBoard()
{
}

void GameBoard::DisplayBoard()
{
	system("CLS");
	std::cout << "\n*** Game Board ***\n";
	std::cout << "     " << " |1|2|3|\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "     " << i + 1 << "|";
		for (int j = 0; j < 3; j++)
		{
			std::cout << _board[i][j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void GameBoard::ClearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_board[i][j] = '.';
		}
	}
}

bool GameBoard::AddToBoard(char marker, int x, int y)
{
	x--;
	y--;

	if (x < 0 || x > 2 || y < 0 || y > 2) {
		return false;
	}
	
	if (_board[y][x] != '.') {
		return false;
	}

	_board[y][x] = marker;

	return true;
}
bool GameBoard::WinnerExists()
{
	if (_board[0][0] != '.' && _board[0][0] == _board[1][1] && _board[1][1] == _board[2][2]) {
		return true;
	}
	if (_board[0][2] != '.' && _board[0][2] == _board[1][1] && _board[1][1] == _board[2][0]) {
		return true;
	}

	for (int i = 0; i < 3; i++) {
		if (_board[i][0] != '.' && _board[i][0] == _board[i][1] && _board[i][1] == _board[i][2]) {
			return true;
		}
		if (_board[0][i] != '.' && _board[0][i] == _board[1][i] && _board[1][i] == _board[2][i]) {
			return true;
		}
	}

	return false;
}
