#pragma once
#include "Pos.h"

class Player
{
public:
	void Render();
	void Input();
	void GroundCheck();
	POS pos = { 0,0 };
	float OnGroundStartTime = 0;
private:
	float OnGroundTime = 0;
};

