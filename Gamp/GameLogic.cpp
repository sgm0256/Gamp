#include "GameLogic.h"

void GameLogic::Init()
{
	//map init
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0Àº ºó°ø°£, 1Àº ¶¥
			if (i % 2 == 1)
				arrMap[i][j] = '1';
			else
				arrMap[i][j] = '0';
		}
	}
	m_player.OnGroundStartTime = clock();

	SetCursorVis(false, 1);
}

void GameLogic::Render()
{
	Gotoxy(0, 0);

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (arrMap[i][j] == (char)MAP_TYPE::Air)
				cout << "  ";
			else if (arrMap[i][j] == (char)MAP_TYPE::Ground)
				cout << "£þ";
		}
		cout << endl;
	}

	m_player.Render();
}

void GameLogic::Update()
{
	while (true)
	{
		Render();
		m_player.Input();
		m_player.GroundCheck(arrMap);
	}
}
