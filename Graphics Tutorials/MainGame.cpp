#include "MainGame.h"

#include <iostream>

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystem();
	gameLoop();
}

void MainGame::initSystem()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT) {
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			system("CLS");
			std::cout << sdlEvent.motion.x << ", " << sdlEvent.motion.y;
			break;
		}
	}
}