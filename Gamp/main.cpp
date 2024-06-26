#include "TitleScene.h"
#include "GameLogic.h"
#include "ObjectManager.h"

void LSM();
void SGM();

int main()
{
	//LSM();
	SGM();
}

void LSM()
{
	TitleScene();
}

void SGM()
{
	if (TitleScene())
	{
		GameLogic gameLogic;
		gameLogic.Init();
		gameLogic.Update();
	}
	ObjectManager::DestroyInst();
}