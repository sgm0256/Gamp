#include "GameLogic.h"
#include "EnemySpawn.h"

void GameLogic::Init()
{
	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0Àº ºó°ø°£, 1Àº ¶¥
			if (i % 2 == 1)
				m_ground.arrMap[i][j] = '1';
			else
				m_ground.arrMap[i][j] = '0';
		}
	}
	m_player.OnGroundStartTime = clock();

	m_player.SetGround(m_ground);

	SetCursorVis(false, 1);
}

void GameLogic::Render()
{
	Gotoxy(0, 0);

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (m_ground.arrMap[i][j] == (char)MAP_TYPE::Air)
				cout << "  ";
			else if (m_ground.arrMap[i][j] == (char)MAP_TYPE::Ground)
				cout << "£þ";
		}
		cout << endl;
	}

	m_player.Render();
	enemySpawn.EnemysRender(m_player);
}

void GameLogic::EnemySpawn()
{
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
	{
		enemySpawn.SpawnEnemy();
	}
}


void GameLogic::Update()
{
	while (true)
	{
		Render();
		EnemySpawn();
		m_player.Input();
		m_player.GroundCheck(m_ground.arrMap);
		m_ground.UpdateGround();
	}
}
