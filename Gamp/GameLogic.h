#pragma once
#include "Player.h"
#include "console.h"

const int MAP_WIDTH = 41;
const int MAP_HEIGHT = 20;

class GameLogic
{
private:
	Player m_player;
public:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
	void Init();
	void Render();
	void Update();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};