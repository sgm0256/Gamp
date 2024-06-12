#include "TitleScene.h"
#include "GameLogic.h"

void LSM();
void SGM();

int main()
{
	//LSM();
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