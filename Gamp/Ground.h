#pragma once
#include <vector>
#include "Pos.h"
#include "define.h"

typedef struct ground 
{
	int life;
	POS pos;
}GROUND;

class Ground
{
public:
	void UpdateGround();
public:
	std::vector<GROUND> vecGround;
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
};