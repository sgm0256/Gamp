#include "GameLogic.h"

void GameLogic::Init()
{
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			arrMap[i][j] = 'бы';
		}
	}
}

void GameLogic::Render()
{
	
}
