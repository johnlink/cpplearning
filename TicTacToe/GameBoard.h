#pragma once

class GameBoard
{

public:
	GameBoard();
	~GameBoard();

	void DisplayBoard();
	void ClearBoard();

	bool AddToBoard(char marker, int x, int y);
	bool WinnerExists();

private:
	char _board[3][3];
};

