#pragma once
#include "Pos.h"
#include "Player.h"
class Enemy
{
public:
	Enemy() = default;
	Enemy(POS pos);
	void EnemyRnderer(Player player);
	POS pos;
private:
};

