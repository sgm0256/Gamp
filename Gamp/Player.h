#pragma once
#include "Pos.h"
#include "define.h"

class Player
{
public:
	void Input();
	void Render();
	void GroundCheck(char arrMap[MAP_HEIGHT][MAP_WIDTH]);

	float OnGroundStartTime = 0;
	POS pos = { 0,0 };
private:
	void Move(POS pos);

private:
	float OnGroundTime = 0;
};

