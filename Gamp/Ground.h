#pragma once
#include <vector>
#include "Object.h"
#include "define.h"

class Ground : public Object
{
public:
	virtual void ObjectUpdate();
	void GroundCheck();
public:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
	float OnGroundStartTime;
private:
	std::vector<OBJECT> vecGround;
	int debug = 1;
};