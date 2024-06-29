#pragma once
#include <vector>
#include "Player.h"
#include "Pos.h"

typedef struct enemyObj
{
	int moveDelay;
	POS pos;

	enemyObj() : moveDelay(0), pos({ 0,0 }) {}
}ENEMYOBJ;

class Enemy
{
public:
	void Update();
	void RemoveEnemy(POS pos);
private:
	void SpawnEnemy();
	void EnmeyMove();
public:
	clock_t enemySpawnStartTimer;
private:
	std::vector<ENEMYOBJ> vecEnemy;
	int moveDelayTime = 5;
	float enemySpawnSpeed = 1;
};
