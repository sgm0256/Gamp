#pragma once
#include <vector>
#include "Player.h"
#include "Pos.h"

typedef struct enemyObj
{
	POS pos;

	enemyObj() : pos({ 0,0 }) {}
}ENEMYOBJ;

class Enemy
{
public:
	void Update();
private:
	void SpawnEnemy();
	void EnmeyMove();
	std::vector<ENEMYOBJ> vecEnemy;
};
