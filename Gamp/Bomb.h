#pragma once
#include <vector>
#include "define.h"

class Bomb
{
public:
	void Update();
	void SpawnBomb(POS pos);
private:
	void ObjectUpdate();
	void UpgradeBombTimer();
public:
	clock_t startBombUpgradeTime;
private:
	std::vector<OBJECT> vecBomb;
	int bombSize = 2;
	int bombLife = 10;
};