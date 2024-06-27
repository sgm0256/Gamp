#include "GameLogic.h"
#include "ObjectManager.h"


void GameLogic::Init()
{
	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0�� �����, 1�� ��
			if (i % 2 == 1)
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Ground;
			else
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Air;
		}
	}
	ObjectManager::GetInst()->m_ground.OnGroundStartTime = clock();

	SetCursorVis(false, 1);
}

void GameLogic::Render()
{
	Gotoxy(0, 0);

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (i == ObjectManager::GetInst()->m_player.pos.y && j == ObjectManager::GetInst()->m_player.pos.x/2)
				ObjectManager::GetInst()->m_player.Render();
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Air)
				cout << "  ";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Ground)
				cout << "��";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Bomb)
				cout << "��";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Flash_Bomb)
				cout << "��";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Enemy)
				cout << "��";
		}
		cout << endl;
	}

	ObjectManager::GetInst()->m_enemy.EnemyRnderer();
}

void GameLogic::EnemySpawn()
{
	if(GetAsyncKeyState(VK_LCONTROL) & 0x8000)
		ObjectManager::GetInst()->enmeySpawn.SpawnEnemy();
}

void GameLogic::Update()
{
	while (true)
	{
		Render();
		ObjectManager::GetInst()->m_player.Input();
		//ObjectManager::GetInst()->m_ground.Update();
		ObjectManager::GetInst()->m_bomb.ObjectUpdate();
		EnemySpawn();
	}
}
