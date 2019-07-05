#pragma once
#include "Ship.h"

class Board;

class Fleet
{
private:
	Board &board;
	std::vector<Ship> fleet;
	
	void CreateShip();
	Vector2i FindPos(int size, bool is_vertical);
	void DestroyShip(int index);
public:
	Fleet(Board &b);
	char GetValue(Vector2i &pos);
	bool Shoot(Vector2i &pos);
	bool isAlive();
	~Fleet();
};

