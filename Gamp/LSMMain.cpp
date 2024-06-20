#include "TitleScene.h"
#include "GameLogic.h"

void LSM()
{
	//TitleScene();
	if (TitleScene())
	{
		GameLogic gameLogic = GameLogic();
		gameLogic.Init();
		gameLogic.Render();
		gameLogic.Update();
	}
}

int main()
{
	LSM();
}