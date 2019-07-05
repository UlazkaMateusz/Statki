#pragma once
#include "Vector2i.h"
#include <vector>

class Ship
{
private:
	std::vector<bool> body;
	bool is_vertical;
	Vector2i pos;
	int GetIndex(Vector2i &target);
public:
	Ship();
	Ship(Vector2i &pos, bool is_v, int size);

	bool isAlive();
	bool isVertical();
	int getSize();
	int getRemainingHp();
	bool getHit(Vector2i &target);
	bool isShip(Vector2i &target);
	char getValue(Vector2i &target);
	bool isInShipArea(Vector2i &target);
	Vector2i getPos();
	void changePos(Vector2i &new_pos);
	~Ship();
};

