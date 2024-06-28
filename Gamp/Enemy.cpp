#include "Enemy.h"
#include "console.h"
#include "ObjectManager.h"
#include<algorithm>

void Enemy::EnemyRnderer()
{
	int time = clock();
	Gotoxy(40, 25);
	EnmeyMove();
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].y][vecEnemy[i].x/2] = (char)OBJ_TYPE::Enemy;
	}
}

void Enemy::EnmeyMove()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		ObjectManager::GetInst()->m_ground.arrMap[vecEnemy[i].y][vecEnemy[i].x/2] = (char)OBJ_TYPE::Air;
		float xPos = ObjectManager::GetInst()->m_player.pos.x - vecEnemy[i].x > 0 ? 1 : -1;
		float yPos = (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].y) != 0 ? 
			ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].y > 0? 2 : -2 : 0;
		POS movePos = {xPos, yPos };
		vecEnemy[i] += movePos;
		vecEnemy[i].x = std::clamp(vecEnemy[i].x, 0, (MAP_WIDTH - 1) * 2);
		vecEnemy[i].y = std::clamp(vecEnemy[i].y, 0, MAP_HEIGHT - 2);
	}
}
