#include "Enemy.h"
#include "console.h"
#include "ObjectManager.h"

void Enemy::EnemyRnderer()
{
	for (int i = 0; i < vecEnemy.size(); ++i)
	{
		float xPos = ObjectManager::GetInst()->m_player.pos.x - vecEnemy[i].x;
		float yPos = ObjectManager::GetInst()->m_player.pos.y - vecEnemy[i].y;

		POS movePos = { xPos, yPos };
		vecEnemy[i] += movePos;

		Gotoxy(vecEnemy[i].x, vecEnemy[i].y);
		cout << "£À";
	}
}
