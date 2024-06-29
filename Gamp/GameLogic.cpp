#include<time.h>
#include "GameLogic.h"
#include "ObjectManager.h"


void GameLogic::Init()
{

	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0은 빈공간, 1은 땅
			if (i % 2 == 1)
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Ground;
			else
				ObjectManager::GetInst()->m_ground.arrMap[i][j] = (char)OBJ_TYPE::Air;
		}
	}
	ObjectManager::GetInst()->m_ground.onGroundStartTime = clock();
	ObjectManager::GetInst()->m_enemy.enemySpawnStartTimer = clock();
	ObjectManager::GetInst()->m_player.lastBombTime = clock();

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
				cout << "￣";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Bomb)
				cout << "◎";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Flash_Bomb)
				cout << "⊙";
			else if (ObjectManager::GetInst()->m_ground.arrMap[i][j] == (char)OBJ_TYPE::Enemy)
				cout << "＠";
		}
		cout << endl;
	}
}

void GameLogic::Update()
{
	clock_t gameOverStartTimer;
	clock_t gameOverEndTimer;
	gameOverStartTimer = clock();
	int gamePlayTime = 20;

	while (true)
	{

		if (ObjectManager::GetInst()->m_endingScene.isGameEnd)
		{
			ObjectManager::GetInst()->m_endingScene.EndingAnimation(false);
			break;
		}
		gameOverEndTimer = clock();
		GotoPos(MAP_WIDTH*2 + 5, 0);
		int currentTimer;
		currentTimer = gamePlayTime - (gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC;
		if(currentTimer % 60 < 10)
			cout << "남은 시간: " << currentTimer / 60 << " : " << "0" << currentTimer % 60;
		else
			cout << "남은 시간: " << currentTimer / 60 << " : " << currentTimer % 60;
		if ((gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC < gamePlayTime)
		{
			Render();
			ObjectManager::GetInst()->m_player.Update();
			ObjectManager::GetInst()->m_ground.Update();
			ObjectManager::GetInst()->m_bomb.ObjectUpdate();
			ObjectManager::GetInst()->m_enemy.Update();
		}
		else
		{
			ObjectManager::GetInst()->m_endingScene.EndingAnimation(true);
			break;
		}
			

	}

}
