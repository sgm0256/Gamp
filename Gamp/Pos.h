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
}POS;