#include<time.h>
#include "GameLogic.h"
#include "ObjectManager.h"


void GameLogic::Init()
{
	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0Àº ºó°ø°£, 1Àº ¶¥
			if (i % 2 == 1)
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Ground;
			else
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Air;
		}
	}
	ObjectManager::GetInst()->m_ground.onGroundStartTime = clock();
	ObjectManager::GetInst()->enmeySpawn.enemySpawnStartTimer = clock();

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
				cout << "£þ";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Bomb)
				cout << "¡Ý";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Flash_Bomb)
				cout << "¢Á";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Enemy)
				cout << "£À";
		}
		cout << endl;
	}

	ObjectManager::GetInst()->m_enemy.EnemyRnderer();
}

void GameLogic::EnemySpawn()
{
	clock_t enemySpawnEndTimer;
	enemySpawnEndTimer = clock();
	if ((enemySpawnEndTimer - ObjectManager::GetInst()->enmeySpawn.enemySpawnStartTimer)
		/ CLOCKS_PER_SEC >0.5f)
	{
		ObjectManager::GetInst()->enmeySpawn.SpawnEnemy();
		ObjectManager::GetInst()->enmeySpawn.enemySpawnStartTimer = clock();
	}
	Gotoxy(40, 25);
	cout << (enemySpawnEndTimer - ObjectManager::GetInst()->enmeySpawn.enemySpawnStartTimer)
		/ CLOCKS_PER_SEC;
}

void GameLogic::Update()
{
	clock_t gameOverEndTimer;
	clock_t gameOverStartTimer;
	gameOverStartTimer = clock();
	while (true)
	{
		/*gameOverEndTimer = clock();
		GotoPos(5, 25);
		cout << (gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC;
		if ((gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC < 20)
		{
			Render();
			ObjectManager::GetInst()->m_player.Input();
			ObjectManager::GetInst()->m_ground.Update();
			ObjectManager::GetInst()->m_bomb.ObjectUpdate();
			EnemySpawn();
		}
		else {
			system("cls");
			break;
		}*/
		Render();
		ObjectManager::GetInst()->m_player.Input();
		ObjectManager::GetInst()->m_ground.Update();
		ObjectManager::GetInst()->m_bomb.ObjectUpdate();
		EnemySpawn();


	}

}
