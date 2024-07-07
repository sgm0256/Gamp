#pragma once
#include<iostream>
#include <vector>
#include "console.h"
#include "Pos.h"
#define SAFE_DELETE(p) if (p != nullptr) {delete p; p = nullptr;}
using std::cout;
using std::endl;
const int MAP_WIDTH = 40;
const int MAP_HEIGHT = 20;
enum class OBJ_TYPE {
	Air = '0',
	Ground,
	Bomb,
	Flash_Bomb,
	Enemy,
	Warning
};

typedef struct object {
	int life;
	POS pos;

	object() : life(0), pos({ 0, 0 }) {}
}OBJECT;