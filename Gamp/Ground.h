#pragma once
#include "define.h"

class Ground
{
public:
	void Update();
private:
	virtual void ObjectUpdate();
	void GroundCheck();
	void GroundBreak();
public:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
	clock_t onGroundStartTime;
	std::vector<OBJECT> vecGround;
	int debug = 1;
};