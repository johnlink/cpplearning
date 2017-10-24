#include "Level.h"
#include "Player.h"

#include <fstream>
#include <stdlib.h>


Level::Level()
{
}


void Level::load(string fileName, Player &player)
{
	ifstream file;
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;

	while (getline(file, line))
	{
		_levelData.push_back(line);
	}

	file.close();

	// Process level
	char tile;
	for (unsigned int i = 0; i < _levelData.size(); i++)
	{
		for (unsigned int j = 0; j < _levelData[i].size(); j++)
		{
			tile = _levelData[i][j];

			switch (tile)
			{
			case '@': // Player
				player.setPosition(j, i);
				break;
			case 'S': // Snake
				_enemies.push_back(Enemy("Snake", tile, 1, 3, 1, 10, 10));
				_enemies.back().setPosition(j, i);
				break;
			case 'G': // Goblin
				_enemies.push_back(Enemy("Goblin", tile, 2, 10, 5, 35, 50));
				_enemies.back().setPosition(j, i);
				break;
			case 'O': // Ogre
				_enemies.push_back(Enemy("Ogre", tile, 4, 20, 20, 200, 500));
				_enemies.back().setPosition(j, i);
				break;
			case 'D': // Dragon
				_enemies.push_back(Enemy("Dragon", tile, 100, 2000, 2000, 20000, 50000000));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}
}

void Level::print()
{
	system("CLS");
	for (unsigned int i = 0; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player &player)
{
	// Get current position of player
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	// Get position where player wants to move to
	switch (input)
	{
	case 'w': //up
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's': // down
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a': // left
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd': // right
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	}
}

void Level::processPlayerMove(Player &player, int targetX, int targetY)
{
	// Get current position of player
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	// Move player based on position's current tile
	char moveTile = getTile(targetX, targetY);
	switch (moveTile)
	{
	case '#':
		// Ran into Wall, don't do anything.
		break;
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	default:
		battleMontser(player, targetX, targetY);
		break;
	}
}

void Level::battleMontser(Player &player, int targetX, int targetY)
{
	int enemyX, enemyY;

	for (unsigned int i = 0; i < _enemies.size(); i++)
	{
		_enemies[i].getPosition(enemyX, enemyY);
		if (targetX == enemyX && targetY == enemyY)
		{
			// Battle
			int attackResult = _enemies[i].takeDamage(player.attack());
			if (attackResult != 0)
			{
				player.addExperience(attackResult);
				setTile(targetX, targetY, '.');
				return;
			}

			if (player.takeDamage(_enemies[i].attack()) > 0) {
				setTile(targetX, targetY, 'X');
				print();
				printf("\nYOU DIED!\n");
				system("PAUSE");
				exit(0);
			}
			return;
		}
	}
}

char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	_levelData[y][x] = tile;
}