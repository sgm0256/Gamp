#include "EnemySpawn.h"
#include "GameLogic.h"
#include <ctime>

void EnemySpawn::SpawnEnemy()
{
	srand((unsigned int)time(NULL));
	int xPos = rand() % 101 >= 50 ? 0 : MAP_WIDTH;
	int yPos = rand() % 101 >= 50 ? 0 : MAP_HEIGHT;
	//POS spawnPos = { xPos,yPos };
	POS spawnPos = { MAP_WIDTH,MAP_HEIGHT/2 };
	Enemy enemy(spawnPos);
	eneymContainerList.push_back(enemy);
}
