#pragma once
#include <vector>
#include "define.h"

class Bomb
{
public:
	virtual void ObjectUpdate();

	std::vector<OBJECT> vecBomb;
private:
	float startBombTime;
	int bombSize = 5;
};