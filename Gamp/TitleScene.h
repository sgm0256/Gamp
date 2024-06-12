#pragma once
void TitleRenderer();
bool TitleScene();
enum class MENU
{
	START, INFO, QUIT
};
MENU MenuRender();
enum class KEY
{
	UP, DOWN, SPACE, FALL
};
KEY KeyControllor();
void EnterAnimation();
void InfoRenderer();