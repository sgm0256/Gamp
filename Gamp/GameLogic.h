#pragma once
#include "Player.h"
#include "console.h"

const int MAP_WIDTH = 41;
const int MAP_HEIGHT = 21;

class GameLogic
{
private:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
	Player m_player;
public:
	void Init();
	void Render();
	void Update();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};