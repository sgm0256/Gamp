#include <ctime>
#include "EnemySpawn.h"
#include "GameLogic.h"
#include "ObjectManager.h"

void EnemySpawn::SpawnEnemy()
{
	srand((unsigned int)time(NULL));
	int xPos = rand() % 101 >= 50 ? 0 : MAP_WIDTH;
	int yPos = rand() % 101 >= 50 ? 0 : MAP_HEIGHT;
	POS spawnPos = { xPos,yPos };
	//POS spawnPos = { MAP_WIDTH,MAP_HEIGHT/2 };
	ObjectManager::GetInst()->
		m_enemy.vecEnemy.push_back({spawnPos.x, spawnPos.y});
}
