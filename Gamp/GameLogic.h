#pragma once
#include "Player.h"
#include "EnemySpawn.h"
#include "console.h"
#include "define.h"

class GameLogic
{
private:
	Player m_player;
	EnemySpawn enmeySpawn;

	char arrMap[MAP_HEIGHT][MAP_WIDTH];
public:
	void Init();
	void Update();
	void Render();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};