#include <math.h>
#include <time.h>
#include "ObjectManager.h"
#include "define.h"

void Bomb::Update()
{
	ObjectUpdate();
	UpgradeBombTimer();
}

void Bomb::ObjectUpdate()
{
	int boomInterval = 5; //Æø¹ß °£°Ý

	for (int i = 0; i < vecBomb.size(); ++i)
	{
		vecBomb[i].life--;
		ObjectManager::GetInst()->m_ground.arrMap[vecBomb[i].pos.y][vecBomb[i].pos.x / 2] =
			(vecBomb[i].life % boomInterval >= boomInterval / 2) ?
			(char)OBJ_TYPE::Bomb : (char)OBJ_TYPE::Flash_Bomb;

		if (vecBomb[i].life >= 0) continue;

		POS bombPos = { vecBomb[i].pos.x, vecBomb[i].pos.y + 1 };

		for (int j = bombPos.y - bombSize; j <= bombPos.y + bombSize; ++j)
		{
			for (int k = bombPos.x / 2 - bombSize; k <= bombPos.x / 2 + bombSize; ++k)
			{
				if (j < 0 || j > MAP_HEIGHT - 1 || k < 0 || k > MAP_WIDTH - 1)
					continue;

				int xPos = std::abs(k - bombPos.x / 2);
				int yPos = std::abs(j - bombPos.y);

				if (xPos + yPos <= bombSize)
				{
					if (ObjectManager::GetInst()->m_ground.arrMap[j][k] == (char)OBJ_TYPE::Ground)
						ObjectManager::GetInst()->m_ground.AddGround({ k,j });
					else if (ObjectManager::GetInst()->m_ground.arrMap[j][k] == (char)OBJ_TYPE::Enemy)
						ObjectManager::GetInst()->m_enemy.RemoveEnemy({ k,j });

					ObjectManager::GetInst()->m_ground.arrMap[j][k] = (char)OBJ_TYPE::Air;
				}
			}
		}

		vecBomb.erase(vecBomb.begin() + i);
	}
}

void Bomb::SpawnBomb(POS pos)
{
	OBJECT newObject;
	newObject.life = bombLife;
	newObject.pos = pos;

	vecBomb.push_back(newObject);
}

void Bomb::UpgradeBombTimer()
{
	if (bombSize == 4)
		return;

	clock_t endBombUpgradeTimer = clock();

	if ((endBombUpgradeTimer - startBombUpgradeTime) / CLOCKS_PER_SEC > 30)
	{
		bombSize += 1;
		startBombUpgradeTime = clock();
	}

	GotoPos(MAP_WIDTH * 2 + 5, 4);
	cout << "ÆøÅº ¹üÀ§: " << bombSize-1 << "´Ü°è";
}
