#pragma once
class Vector2i
{
	int x;
	int y;
public:
	Vector2i();
	Vector2i(int x, int y);
	int getX();
	int getY();
	void setX(int a);
	void setY(int a);
	~Vector2i();
};

