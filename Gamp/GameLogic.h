#pragma once
#include "Player.h"
#include "EnemySpawn.h"
#include "console.h"
#include "define.h"
#include "Ground.h"

class GameLogic
{
private:
	Ground m_ground;
	Player m_player;
	EnemySpawn enmeySpawn;

public:
	void Init();
	void Update();
	void Render();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};