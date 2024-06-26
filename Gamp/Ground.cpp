#include "Ground.h"
#include "Object.h"

void Ground::UpdateGround()
{
	for (int i = 0; i < vecGround.size(); ++i)
	{
		vecGround[i].life--;
		if (vecGround[i].life == 0) {
			arrMap[vecGround[i].pos.y][vecGround[i].pos.x] = '1';
			vecGround.erase(vecGround.begin() + i);
		}
	}
}

void Ground::GroundCheck()
{
	POS playerStepPos = { Object::GetInst()->m_player.pos.x / 2, Object::GetInst()->m_player.pos.y + 1};

	float OnGroundEndTime = clock();

	//debug
	Gotoxy(0, MAP_HEIGHT);
	cout << (OnGroundEndTime - OnGroundStartTime) / CLOCKS_PER_SEC;

	if ((OnGroundEndTime - OnGroundStartTime) / CLOCKS_PER_SEC > 0.5f)
	{
		if (playerStepPos.y < MAP_HEIGHT && playerStepPos.x < MAP_WIDTH)
		{
			arrMap[playerStepPos.y][playerStepPos.x] = '0';
			vecGround.push_back({
				50,
				playerStepPos
				});
			OnGroundStartTime = clock();
		}
	}
}
