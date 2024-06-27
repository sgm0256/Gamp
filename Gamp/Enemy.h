#pragma once
#include <vector>
#include "Player.h"
#include "Pos.h"

class Enemy
{
public:
	void EnemyRnderer();
	void EnmeyMove();
	std::vector<POS> vecEnemy;
};
