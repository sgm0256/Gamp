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

		if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
		{
			cout << "1";
		}
	}
}

int main()
{
	LSM();
}