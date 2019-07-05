#include "pch.h"
#include "Fleet.h"
#include <ctime>
#include <cstdlib>
#include "Board.h"

Vector2i Fleet::FindPos(int size, bool is_vertical)
{
	Vector2i pos;
	Vector2i tmp_pos;
	bool bad_pos = true;
	while (bad_pos)
	{
		bad_pos = false;
		
		if (is_vertical)
		{
			pos.setX(rand() % 10);
			pos.setY(rand() % (10 - size));
		}
		else
		{
			pos.setX(rand() % (10 - size));
			pos.setY(rand() % 10);
		}

		tmp_pos = pos;

		for (int i = 0; i < size; i++)
		{
			if (is_vertical)
			{
				for (int j = 0; j < fleet.size(); j++)
				{
					tmp_pos.setY(pos.getY() + i);
					if (fleet[j].isInShipArea(tmp_pos))
						bad_pos = true;
				}
			}
			else
			{
				for (int j = 0; j < fleet.size(); j++)
				{
					tmp_pos.setX(pos.getX() + i);
					if (fleet[j].isInShipArea(tmp_pos))
						bad_pos = true;
				}
			}
		}
	}
	return pos;
}

void Fleet::DestroyShip(int index)
{
	Vector2i shoot_pos = fleet[index].getPos();
	int ship_x = shoot_pos.getX();
	int ship_y = shoot_pos.getY();

	int size = fleet[index].getSize();
	bool is_vertical = fleet[index].isVertical();

	for (int i = -1; i < size +1; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			shoot_pos.setX(ship_x + !is_vertical * i + is_vertical * j);
			shoot_pos.setY(ship_y + is_vertical * i + !is_vertical * j);
			board.ShootAt(shoot_pos);

		}
	}

	fleet.erase(fleet.begin() + index);
}

Fleet::Fleet(Board &b) : board(b)
{
	srand(time(NULL));
	
	for (int i=0; i<10; i++)
		CreateShip();
}

char Fleet::GetValue(Vector2i &pos)
{
	for (int i = 0; i < fleet.size(); i++)
	{
		if (fleet[i].getValue(pos) != 'E')
			return fleet[i].getValue(pos);
	}
	
	return 'E';
}

bool Fleet::Shoot(Vector2i &pos)
{
	for (int i = 0; i < fleet.size(); i++)
		if (fleet[i].getHit(pos))
		{
			if (fleet[i].isAlive())
				return true;
			else
			{
				DestroyShip(i);
			}
		}


	return false;
}

bool Fleet::isAlive()
{
	for (int i = 0; i < fleet.size(); i++)
	{
		if (fleet[i].isAlive())
			return true;
	}
	
	return false;
}

void Fleet::CreateShip()
{
	int size;
	if (fleet.size() == 0)
		size = 4;
	else if (fleet.size() >= 1 && fleet.size() < 3)
		size = 3;
	else if (fleet.size() >= 3 && fleet.size() < 6)
		size = 2;
	else if (fleet.size() >= 6)
		size = 1;

	bool is_vertical = rand() % 2;
	Vector2i pos = FindPos(size, is_vertical);
	fleet.push_back(Ship(pos, is_vertical, size));
}

Fleet::~Fleet()
{
}
