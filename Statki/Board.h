#pragma once
#include <iostream>
#include "Ship.h"
#include "Fleet.h"
#include "Vector2i.h"

class Board
{
private:
	char board[10][10];
	Fleet fleet;
public:
	Board();
	~Board();
	void ShootAt(Vector2i pos);
	void GetInput();

	friend std::ostream& operator<<(std::ostream& stream, Board& board);
};

