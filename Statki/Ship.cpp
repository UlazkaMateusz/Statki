#include "pch.h"
#include "Ship.h"

int Ship::GetIndex(Vector2i & target)
{
	if (is_vertical)
		return target.getY() - pos.getY();
	else
		return target.getX() - pos.getX();
}

Ship::Ship()
{
	pos = Vector2i(-100, -100);
	is_vertical = true;
	body.push_back(true);
}

Ship::Ship(Vector2i &p, bool vertical, int size)
{
	pos = p;
	is_vertical = vertical;
	for (int i = 0; i < size; i++)
		body.push_back(true);
}

bool Ship::isAlive()
{
	if (getRemainingHp() > 0)
		return true;

	return false;
}

bool Ship::isVertical()
{
	return is_vertical;
}

int Ship::getSize()
{
	return body.size();
}

int Ship::getRemainingHp()
{
	int hp = 0;
	for (int i = 0; i < body.size(); i++)
		if (body[i])
			hp++;

	return hp;
}

bool Ship::getHit(Vector2i &target)
{
	if (!isShip(target))
		return false;

	int index = GetIndex(target);

	if (body[index])
	{
		body[index] = false;
		return true;
	}
	else
		return false;
}

bool Ship::isShip(Vector2i &target)
{
	if (is_vertical)
	{
		if (pos.getX() == target.getX() &&
			target.getY() >= pos.getY() &&
			target.getY() < pos.getY() + body.size())
				return true;
	}
	else
	{
		if (pos.getY() == target.getY() &&
			target.getX() >= pos.getX() &&
			target.getX() < pos.getX() + body.size())
				return true;
	}

	return false;
}

char Ship::getValue(Vector2i &target)
{
	if (!isShip(target))
		return 'E';

	// Change '*' to 'O' to show ships
	if (body[GetIndex(target)])
		return '*';
	else
		return 'X';
}

bool Ship::isInShipArea(Vector2i &target)
{
	if (is_vertical)
	{
		if (pos.getX() - 1 <= target.getX() &&
			pos.getX() + 1 >= target.getX() &&
			pos.getY() - 1 <= target.getY() &&
			pos.getY() + body.size() + 1 >= target.getY())
			return true;
	}
	else
	{
		if (pos.getY() - 1 <= target.getY() &&
			pos.getY() + 1 >= target.getY() &&
			pos.getX() - 1 <= target.getX() &&
			pos.getX() + body.size() + 1 >= target.getX())
			return true;
	}

	return false;
}

Vector2i Ship::getPos()
{
	return pos;
}

void Ship::changePos(Vector2i &new_pos)
{
	pos = new_pos;
}

Ship::~Ship() {}