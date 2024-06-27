#include "Enemy.h"
#include "console.h"
#include "ObjectManager.h"
#include<algorithm>

void Enemy::EnemyRnderer()
{
	EnmeyMove();
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		Gotoxy(vecEnemy[i].x, vecEnemy[i].y);
		cout << "£À";
	}
}

void Enemy::EnmeyMove()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		float xPos = ObjectManager::GetInst()->m_player.pos.x - vecEnemy[i].x > 0 ? 1 : -1;
		float yPos = (ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].y) > 0 ? 2 : -2;

		POS movePos = {xPos, yPos };
		vecEnemy[i] += movePos;
		vecEnemy[i].x = std::clamp(vecEnemy[i].x, 0, (MAP_WIDTH - 1) * 2);
		vecEnemy[i].y = std::clamp(vecEnemy[i].y, 0, MAP_HEIGHT - 2);
	}
}
