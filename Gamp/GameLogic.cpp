#include "define.h"
#include "GameLogic.h"

void GameLogic::Init()
{
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			//0Àº ºó°ø°£ 1ÀÎ ¶¥
			if (i % 2 == 1)
				arrMap[i][j] = '1';
		}
	}
}

void GameLogic::Render()
{
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if(i == 0 && j == 0)
				cout << "¡Ú¥°"

			if (arrMap[i][j] == (char)MAP_TYPE::Air)
				cout << " ";
			else if (arrMap[i][j] == (char)MAP_TYPE::Ground)
				cout << "£þ";
		}
		cout << endl;
	}
}
