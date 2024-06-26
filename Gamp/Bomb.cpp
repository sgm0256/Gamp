#include <math.h>
#include "ObjectManager.h"
#include "define.h"

void Bomb::ObjectUpdate()
{
	int boomInterval = 5; //���� ����

	for (int i = 0; i < vecBomb.size(); ++i)
	{
		vecBomb[i].life--;
		ObjectManager::GetInst()->m_ground.arrMap[vecBomb[i].pos.y][vecBomb[i].pos.x / 2] =
			(vecBomb[i].life % boomInterval >= boomInterval / 2) ?
			(char)OBJ_TYPE::Bomb : (char)OBJ_TYPE::Flash_Bomb;
		if (vecBomb[i].life == 0)
		{
			/*for (int j = vecBomb[i].pos.y - bombSize; j <= vecBomb[i].pos.y + bombSize; ++j)
			{
				for (int k = vecBomb[i].pos.x - bombSize; k <= vecBomb[k].pos.x + bombSize; ++k)
				{
					if(std::abs(ObjectManager::GetInst()->m_ground.arrMap[j][k] - vecBomb[i].pos.x) + std::abs(ObjectManager::GetInst()->m_ground.arrMap[j][k] - vecBomb[i].pos.x)
				}
			}*/

			vecBomb.erase(vecBomb.begin() + i);
		}
	}
}
