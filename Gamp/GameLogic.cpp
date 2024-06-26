#include "GameLogic.h"
#include "Object.h"


void GameLogic::Init()
{
	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0Àº ºó°ø°£, 1Àº ¶¥
			if (i % 2 == 1)
				Object::GetInst()->m_ground.arrMap[i][j] = '1';
			else
				Object::GetInst()->m_ground.arrMap[i][j] = '0';
		}
	}
	Object::GetInst()->m_ground.OnGroundStartTime = clock();

	SetCursorVis(false, 1);
}

void GameLogic::Render()
{
	Gotoxy(0, 0);

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (i == Object::GetInst()->m_player.pos.y && j == Object::GetInst()->m_player.pos.x / 2)
				Object::GetInst()->m_player.Render();
			else if (Object::GetInst()->m_ground.arrMap[i][j] == (char)MAP_TYPE::Air)
				cout << "  ";
			else if (Object::GetInst()->m_ground.arrMap[i][j] == (char)MAP_TYPE::Ground)
				cout << "£þ";
		}
		cout << endl;
	}
}

void GameLogic::EnemySpawn()
{
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
		Object::GetInst()->enmeySpawn.SpawnEnemy();
}

void GameLogic::Update()
{
	while (true)
	{
		Render();
		Object::GetInst()->m_player.Input();
		Object::GetInst()->m_ground.GroundCheck();
		Object::GetInst()->m_ground.UpdateGround();
		EnemySpawn();
		Object::GetInst()->enmeySpawn.EnemysRender(Object::GetInst()->m_player);
	}
}
