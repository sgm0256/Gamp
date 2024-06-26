#pragma once
#include "Pos.h"
#include "define.h"
#include "Ground.h"

class Player
{
private:
	void Move(POS _pos);
public:
	void Render();
	void Input();
public:
	POS pos = { 0,0 };
private:
};