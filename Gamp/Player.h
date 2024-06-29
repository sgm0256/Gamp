#pragma once
#include "Pos.h"
#include "define.h"

class Player
{
public:
	void Render();
	void Update();
private:
	void Move(POS _pos);
	void MoveInput();
	void BombInput();
public:
	POS pos = { 0,0 };
};