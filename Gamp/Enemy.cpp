#include "Enemy.h"
#include "console.h"
#include "ObjectManager.h"
#include<algorithm>

void Enemy::Update()
{
	SpawnEnemy();
	EnmeyMove();
}

void Enemy::SpawnEnemy()
{
	clock_t enemySpawnEndTimer = clock();

	if ((enemySpawnEndTimer - enemySpawnStartTimer) / CLOCKS_PER_SEC > 1)
	{
		POS spawnPos = { 0, 0 };

		bool isVerticalSpawn = rand() % 2;
		if (isVerticalSpawn)
		{
			spawnPos.x = rand() % 2 == 0 ? 0 : MAP_WIDTH - 1;
			spawnPos.y = (rand() % MAP_HEIGHT/2) * 2;
		}
		else
		{
			spawnPos.x = rand() % MAP_WIDTH - 1;
			spawnPos.y = rand() % 2 > 0 ? 0 : MAP_HEIGHT - 2;
		}

		Gotoxy(0, MAP_HEIGHT);
		cout << spawnPos.x << ", " << spawnPos.y << "  ";

		ENEMYOBJ newEnemyObj;
		newEnemyObj.pos = spawnPos;
		vecEnemy.push_back(newEnemyObj);

		enemySpawnStartTimer = clock();
	}
}

void Enemy::EnmeyMove()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x] = (char)OBJ_TYPE::Air;

		POS movePos = { 0,0 };

		if (ObjectManager::GetInst()->m_player.pos.x/2 - vecEnemy[i].pos.x > 0)
			movePos.x = 1;
		else if (ObjectManager::GetInst()->m_player.pos.x/2 - vecEnemy[i].pos.x < 0)
			movePos.x = -1;

		if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y > 0)
			movePos.y = 2;
		else if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y < 0)
			movePos.y = -2;

		vecEnemy[i].pos += movePos;

		vecEnemy[i].pos.x = std::clamp(vecEnemy[i].pos.x, 0, (MAP_WIDTH - 1) * 2);
		vecEnemy[i].pos.y = std::clamp(vecEnemy[i].pos.y, 0, MAP_HEIGHT - 2);

		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x] = (char)OBJ_TYPE::Enemy;
	}
}
