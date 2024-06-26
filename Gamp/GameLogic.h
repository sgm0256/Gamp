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
	EnemySpawn enemySpawn;

public:
	void Init();
	void Update();
	void Render();
	void EnemySpawn();
};

enum class MAP_TYPE {
	Air = '0',
	Ground
};