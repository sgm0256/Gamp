#include "ObjectManager.h"
#include "Ground.h"

void Ground::Update()
{
	ObjectUpdate();
	//GroundCheck();
}

void Ground::ObjectUpdate()
{
	for (int i = vecGround.size() - 1; i >= 0; --i)
    {
        vecGround[i].life--;
        if (vecGround[i].life == 0) {
            arrMap[vecGround[i].pos.y][vecGround[i].pos.x] = (char)OBJ_TYPE::Ground;
            vecGround.erase(vecGround.begin() + i);
        }
    }
}

void Ground::GroundCheck()
{
	POS playerStepPos = { ObjectManager::GetInst()->m_player.pos.x / 2, ObjectManager::GetInst()->m_player.pos.y + 1 };

	clock_t OnGroundEndTime = clock();

	//debug
	Gotoxy(0, MAP_HEIGHT);
	cout << (OnGroundEndTime - onGroundStartTime) / CLOCKS_PER_SEC;

	if ((OnGroundEndTime - onGroundStartTime) / CLOCKS_PER_SEC > 0.5f)
	{
		if (playerStepPos.y < MAP_HEIGHT && playerStepPos.x < MAP_WIDTH)
		{
			arrMap[playerStepPos.y][playerStepPos.x] = (char)OBJ_TYPE::Air;

			OBJECT newObject;
			newObject.life = 50;
			newObject.pos = playerStepPos;

			//vecGround.push_back(newObject);

			onGroundStartTime = clock();
		}
	}
}
