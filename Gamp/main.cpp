#include "TitleScene.h"
#include "GameLogic.h"

int main()
{
	LSM();
	SGM();
}

void LSM() 
{
	TitleRenderer();
}

void SGM() 
{
	GameLogic gameLogic = GameLogic();
	gameLogic.Init();
	gameLogic.Render();
}