#pragma once
#include <vector>
#include "define.h"

class Bomb
{
public:
	virtual void ObjectUpdate();
	void SpawnBomb(POS pos);

private:
	std::vector<OBJECT> vecBomb;
	float startBombTime;
	int bombSize = 4;
	int bombLife = 10;
};