#pragma once
#include <vector>
#include "Object.h"

class Bomb : public Object
{
public:
	virtual void ObjectUpdate();

	std::vector<OBJECT> vecBomb;
private:
	float startBombTime;
	int bombSize = 2;
};