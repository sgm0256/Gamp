#pragma once

typedef struct pos
{
	int x;
	int y;

	pos& operator+=(const pos& other) 
	{
		x += other.x;
		y += other.y; 
		return *this;
	}

	bool operator==(const pos& other) const
	{
		return x == other.x && y == other.y;
	}
}POS;