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
	ObjectManager::GetInst()->m_enemy.enemySpawnStartTimer = clock();

	SetCursorVis(false, 1);
	srand((unsigned int)time(NULL));
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
}

void GameLogic::Update()
{
	clock_t gameOverStartTimer;
	clock_t gameOverEndTimer;
	gameOverStartTimer = clock();
	//int timeCnt = 20;

	while (true)
	{
		gameOverEndTimer = clock();
		GotoPos(15, MAP_HEIGHT);
		int currentTimer;
		currentTimer = 250 - (gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC;
		if(currentTimer % 60 < 10)
			cout << currentTimer/60 << " : " << "0" << currentTimer % 60;
		else
			cout << currentTimer / 60 << " : " << currentTimer % 60;
		if ((gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC < 300)
		{
			Render();
			ObjectManager::GetInst()->m_player.Input();
			ObjectManager::GetInst()->m_ground.Update();
			ObjectManager::GetInst()->m_bomb.ObjectUpdate();
			ObjectManager::GetInst()->m_enemy.Update();
		}
		else {
			//system("cls");
			break;
		}
	}

}
