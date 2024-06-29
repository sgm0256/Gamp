#include "TitleScene.h"
#include "GameLogic.h"
#include "ObjectManager.h"

int main()
{
	if (TitleScene())
	{
		GameLogic gameLogic;
		gameLogic.Init();
		gameLogic.Update();
	}
	ObjectManager::DestroyInst();
}