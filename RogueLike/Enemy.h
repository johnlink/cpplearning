#pragma once
#include <string>

class Enemy
{
public:
	Enemy(std::string name, char tile, int level, int attack, int defense, int health, int experienceValue);
	
	int attack();
	int takeDamage(int attack);
		
	void setPosition(int x, int y);

	void getPosition(int &x, int &y);

private:
	std::string _name;
	char _tile;

	int _level, _attack, _defense, _health, _experienceValue;

	// Position
	int _x;
	int _y;
	

};

