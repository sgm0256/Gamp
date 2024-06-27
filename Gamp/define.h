#pragma once
#include<iostream>
#include "console.h"
#define SAFE_DELETE(p) if (p != nullptr) {delete p; p = nullptr;}
using std::cout;
using std::endl;
const int MAP_WIDTH = 41;
const int MAP_HEIGHT = 20;
enum class OBJ_TYPE {
	Air = '0',
	Ground,
	Bomb,
	Flash_Bomb,
	Enemy
};