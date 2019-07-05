#include "pch.h"
#include "Vector2i.h"

Vector2i::Vector2i() : x(-100), y(-100)
{
}

Vector2i::Vector2i(int x, int y) : x(x), y(y)
{
}

int Vector2i::getX()
{
	return x;
}


int Vector2i::getY()
{
	return y;
}

void Vector2i::setX(int a)
{
	x = a;
}

void Vector2i::setY(int a)
{
	y = a;
}

Vector2i::~Vector2i()
{
}
