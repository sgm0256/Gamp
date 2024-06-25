#pragma once
#include "Pos.h"
#include "define.h"
#include "Ground.h"

class Player
{
private:
	void Move(POS _pos);
public:
	void SetGround(Ground& ground);
	void Render();
	void Input();
	void GroundCheck(char arrMap[MAP_HEIGHT][MAP_WIDTH]);

	POS pos = { 0,0 };
	float OnGroundStartTime = 0;
private:
	Ground* pGround;
	float OnGroundTime = 0;
};