#include "pch.h"
#include "Board.h"
#include <iomanip>
#include <iostream>
#include <string>


Board::Board() : fleet(Fleet(*this))
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			Vector2i pos = Vector2i(i, j);
			char value = fleet.GetValue(pos);
			if (value != 'E')
				board[i][j] = value;
			else
				board[i][j] = '*';
		}
}


Board::~Board()
{
}

void Board::ShootAt(Vector2i pos)
{
	int x = pos.getX();
	int y = pos.getY();
	
	if (x < 0  || x >= 10)
		return;

	if (y < 0 || y >= 10)
		return;

	if (!fleet.Shoot(pos))
		board[x][y] = '#';
	else
		board[x][y] = 'X';
}

void Board::GetInput()
{
	system("cls");
	std::cout << *this << std::endl;

	if (fleet.isAlive())
	{
		std::string command;
		std::cout << "Podaj Koordynaty: ";
		std::cin >> command;
	
		int y = command[0] - 65;
		int x = command[1] - 48;

		if (board[x][y] == '#' || board[x][y] == 'X')
		{
			std::cout << "Juz tutaj strzelales!" << std::endl;
			system("pause");
		}

		ShootAt(Vector2i(x, y));
	}
	else
	{
		std::cout << "Nie ma wiecej statkow do pokonania!" << std::endl;
		std::cout << "Wygrana!" << std::endl;
		system("pause");
		exit(0);
	}
}

std::ostream & operator<<(std::ostream & stream, Board & b)
{
	char letters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	stream << std::setw(2) << " ";
	for (int i = 0; i < 10; i++)
		stream << std::setw(2) << letters[i];

	stream << std::endl;

	for (int i = 0; i < 10; i++)
	{
		stream << std::setw(2) << i;
		for (int j = 0; j < 10; j++)
			stream << std::setw(2) << b.board[i][j];

		stream << std::endl;
	}
	return stream;
}



