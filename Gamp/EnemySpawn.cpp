#include "EnemySpawn.h"
#include "GameLogic.h"
#include <ctime>

void EnemySpawn::SpawnEnemy()
{
	{
		srand((unsigned int)time(NULL));
		int xPos = rand() % 50 >= 50 ? 0 : MAP_WIDTH;
		int yPos = rand() % 50 >= 50 ? 0 : MAP_HEIGHT;
		POS spawnPos = { MAP_WIDTH,MAP_HEIGHT / 2 + 1 };
		Enemy enemy;
		enemy.pos = spawnPos;
		eneymContainerList.push_back(enemy);
	}
}
