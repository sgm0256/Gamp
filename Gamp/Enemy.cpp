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
	if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
	{
		srand((unsigned int)time(NULL));
		int xPos = rand() % 101 >= 50 ? 0 : MAP_WIDTH * 2;
		int yPos = rand() % 101 >= 50 ? 0 : MAP_HEIGHT;
		POS spawnPos = { xPos,yPos };
		//POS spawnPos = { MAP_WIDTH,MAP_HEIGHT/2 };

		ENEMYOBJ newEnemyObj;
		newEnemyObj.pos = spawnPos;
		vecEnemy.push_back(newEnemyObj);

		/*Gotoxy(0, MAP_HEIGHT);
		cout << ObjectManager::GetInst()->m_ground.vecGround.size();
		Gotoxy(0, MAP_HEIGHT+1);
		cout << vecEnemy.size();*/
	}
}

void Enemy::EnmeyMove()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x / 2] = (char)OBJ_TYPE::Air;

		POS movePos = { 0,0 };

		if (ObjectManager::GetInst()->m_player.pos.x - vecEnemy[i].pos.x > 0)
			movePos.x = 1;
		else if (ObjectManager::GetInst()->m_player.pos.x - vecEnemy[i].pos.x < 0)
			movePos.x = -1;

		if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y > 0)
			movePos.y = 2;
		else if (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].pos.y < 0)
			movePos.y = -2;

		vecEnemy[i].pos += movePos;

		vecEnemy[i].pos.x = std::clamp(vecEnemy[i].pos.x, 0, (MAP_WIDTH - 1) * 2);
		vecEnemy[i].pos.y = std::clamp(vecEnemy[i].pos.y, 0, MAP_HEIGHT - 2);

		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].pos.y][vecEnemy[i].pos.x / 2] = (char)OBJ_TYPE::Enemy;
	}
}
