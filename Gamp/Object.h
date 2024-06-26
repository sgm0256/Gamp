#pragma once
#include "Pos.h"

class Object
{
public:
	virtual void ObjectUpdate() abstract;
};

typedef struct object {
	int life;
	POS pos;
}OBJECT;