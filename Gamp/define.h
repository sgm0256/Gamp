#pragma once
#include<iostream>
#include "console.h"
using std::cout;
using std::endl;
const int MAP_WIDTH = 41;
const int MAP_HEIGHT = 20;
#define SAFE_DELETE(p) if (p != nullptr) {delete p; p = nullptr;}