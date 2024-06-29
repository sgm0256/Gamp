#include "ObjectManager.h"
#include "Ground.h"

void Ground::Update()
{
	ObjectUpdate();
	GroundCheck();
}

void Ground::ObjectUpdate()
{
	for (int i = 0; i  < vecGround.size(); ++i)
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
	clock_t OnGroundEndTime = clock();

	if ((OnGroundEndTime - onGroundStartTime) / CLOCKS_PER_SEC > 0.5f)
		GroundBreak();
}

void Ground::GroundBreak()
{
	POS playerStepPos = { ObjectManager::GetInst()->m_player.pos.x / 2, ObjectManager::GetInst()->m_player.pos.y + 1 };

	if (playerStepPos.y < MAP_HEIGHT && playerStepPos.x < MAP_WIDTH)
	{
		arrMap[playerStepPos.y][playerStepPos.x] = (char)OBJ_TYPE::Air;

		AddGround(playerStepPos);

		onGroundStartTime = clock();
	}
}


void Ground::AddGround(POS pos)
{
	OBJECT newObject;
	newObject.life = 50;
	newObject.pos = pos;

	vecGround.push_back(newObject);
}
