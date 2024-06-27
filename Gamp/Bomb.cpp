#include <math.h>
#include "ObjectManager.h"
#include "define.h"

void Bomb::ObjectUpdate()
{
	int boomInterval = 5; //Æø¹ß °£°Ý

	for (int i = 0; i < vecBomb.size(); ++i)
	{
		vecBomb[i].life--;
		ObjectManager::GetInst()->m_ground.arrMap[vecBomb[i].pos.y][vecBomb[i].pos.x / 2] =
			(vecBomb[i].life % boomInterval >= boomInterval / 2) ?
			(char)OBJ_TYPE::Bomb : (char)OBJ_TYPE::Flash_Bomb;

		if (vecBomb[i].life == 0)
		{
			POS bombPos = { vecBomb[i].pos.x, vecBomb[i].pos.y + 1 };

			for (int j = bombPos.y - bombSize; j <= bombPos.y + bombSize; ++j)
			{
				for (int k = bombPos.x / 2 - bombSize; k <= bombPos.x / 2 + bombSize; ++k)
				{
					if (j < 0 || j > MAP_HEIGHT-1 || k < 0 || k > MAP_WIDTH-1)
						continue;

					int xPos = std::abs(k - bombPos.x / 2);
					int yPos = std::abs(j - bombPos.y);

					if (xPos + yPos <= bombSize)
					{
						if (ObjectManager::GetInst()->m_ground.arrMap[j][k] == (char)OBJ_TYPE::Ground)
							ObjectManager::GetInst()->m_ground.vecGround.push_back({ 50, {k, j} });

						ObjectManager::GetInst()->m_ground.arrMap[j][k] = (char)OBJ_TYPE::Air;
					}
				}
			}

			vecBomb.erase(vecBomb.begin() + i);
		}
	}
}
