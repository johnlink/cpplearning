#include <iostream>
#include <string>

#include "GameManager.h"
#include "GameBoard.h"


GameManager::GameManager()
{
	_gameBoard = GameBoard();
}


GameManager::~GameManager()
{
}

void GameManager::Start()
{
	bool isDone = false;
	bool validInput = false;

	int x, y;

	int turns = 0;

	std::string again;

	_currentPlayer = _player1;

	while (!isDone)
	{

		_gameBoard.DisplayBoard();

		do {
			x = GetXInput();
			y = GetYInput();

			if (!(validInput = _gameBoard.AddToBoard(_currentPlayer, x, y))) {
				std::cout << "Invalid Entry. Please try again.\n";
			}
		} while (!validInput);

		turns++;

		if (turns == 9) {
			_gameBoard.DisplayBoard();
			std::cout << "Game board is full! Players have tied!\n";
			system("PAUSE");
			turns = 0;
			_gameBoard.ClearBoard();
		} else if (_gameBoard.WinnerExists()) {
			_gameBoard.DisplayBoard();
			std::cout << _currentPlayer << " is the WINNER!!\n";
			system("PAUSE");
			turns = 0;
			_gameBoard.ClearBoard();
		}
		_currentPlayer = _currentPlayer == _player1 ? _player2 : _player1;
	}
	
}

int GameManager::GetXInput()
{
	int input;

	std::cout << _currentPlayer << " please select a col: ";
	std::cin >> input;

	return input;
}

int GameManager::GetYInput()
{
	int input;

	std::cout << _currentPlayer << " please select a row: ";
	std::cin >> input;

	return input;
}