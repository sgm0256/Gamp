#include<algorithm>
#include "Enemy.h"
#include "console.h"
#include "ObjectManager.h"

void Enemy::Update()
{
	SpawnEnemy();
	EnmeyMove();
}

void Enemy::SpawnEnemy()
{
	clock_t enemySpawnEndTimer = clock();

	if ((enemySpawnEndTimer - enemySpawnStartTimer) / CLOCKS_PER_SEC > enemySpawnSpeed)
	{
		enemySpawnSpeed -= 0.001f;

		POS spawnPos = { 0, 0 };

		bool isVerticalSpawn = rand() % 2;
		if (isVerticalSpawn)
		{
			spawnPos.x = rand() % 2 == 0 ? 0 : MAP_WIDTH - 1;
			spawnPos.y = (rand() % MAP_HEIGHT / 2) * 2;
		}
		else
		{
			spawnPos.x = rand() % MAP_WIDTH - 1;
			spawnPos.y = rand() % 2 > 0 ? 0 : MAP_HEIGHT - 2;
		}

		ENEMYOBJ newEnemyObj;
		newEnemyObj.moveDelay = moveDelayTime;
		newEnemyObj.pos = spawnPos;
		vecEnemy.push_back(newEnemyObj);

		enemySpawnStartTimer = clock();
	}
}

void Enemy::EnmeyMove()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		vecEnemy[i].moveDelay--;
		if (vecEnemy[i].moveDelay > 0) continue;
		vecEnemy[i].moveDelay = moveDelayTime;

		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x] = (char)OBJ_TYPE::Air;

		POS movePos = vecEnemy[i].pos;

		if (ObjectManager::GetInst()->m_player.pos.x / 2 - vecEnemy[i].pos.x > 0)
			movePos.x += 1;
		else if (ObjectManager::GetInst()->m_player.pos.x / 2 - vecEnemy[i].pos.x < 0)
			movePos.x += -1;

		if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y > 0)
			movePos.y += 2;
		else if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y < 0)
			movePos.y += -2;

		if (ObjectManager::GetInst()->m_ground.arrMap[movePos.y][movePos.x] == (char)OBJ_TYPE::Air)
			if(ObjectManager::GetInst()->m_ground.arrMap[movePos.y + 1][movePos.x] == (char)OBJ_TYPE::Ground)
				vecEnemy[i].pos = movePos;

		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x] = (char)OBJ_TYPE::Enemy;
	}
}

void Enemy::RemoveEnemy(POS pos)
{
	for (auto it = vecEnemy.begin(); it != vecEnemy.end(); ++it)
	{
		if (it->pos == pos)
		{
			vecEnemy.erase(it);
			return;
		}
	}
}