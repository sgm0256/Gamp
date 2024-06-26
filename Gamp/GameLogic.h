#pragma once
#include "console.h"
#include "define.h"

class GameLogic
{
public:
	void Init();
	void Update();
	void Render();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};