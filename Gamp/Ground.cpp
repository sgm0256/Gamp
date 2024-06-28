#include "ObjectManager.h"
#include "Ground.h"

void Ground::Update()
{
	ObjectUpdate();
	//GroundCheck();
}

void  Ground::ObjectUpdate()
{
	//Gotoxy(0, MAP_HEIGHT + debug);
	//cout << vecGround.size();
	//debug++;

	for (int i = 0; i < vecGround.size(); ++i)
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

	float OnGroundEndTime = clock();

	//debug
	Gotoxy(0, MAP_HEIGHT);
	cout << (OnGroundEndTime - onGroundStartTime) / CLOCKS_PER_SEC;

	if ((OnGroundEndTime - onGroundStartTime) / CLOCKS_PER_SEC > 0.5f)
	{
		if (playerStepPos.y < MAP_HEIGHT && playerStepPos.x < MAP_WIDTH)
		{
			arrMap[playerStepPos.y][playerStepPos.x] = (char)OBJ_TYPE::Air;
			vecGround.push_back({
				50,
				playerStepPos
				});
			onGroundStartTime = clock();
		}
	}
}
