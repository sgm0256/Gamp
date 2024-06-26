#pragma once
#include "Pos.h"
#include "define.h"

class Player
{
private:
	void Move(POS _pos);
public:
	void Render();
	void Input();
private:
	void MoveInput();
	void BombInput();
public:
	POS pos = { 0,0 };
private:
};