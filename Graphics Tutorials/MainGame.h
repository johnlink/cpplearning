#pragma once

#include <SDL.h>

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	SDL_Window* _window;
	GameState _gameState;
	int _screenWidth, _screenHeight;

	void initSystem();
	void gameLoop();
	void processInput();
};