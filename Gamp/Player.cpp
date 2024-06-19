#include "Player.h"
#include "console.h"

void Player::Render()
{
	Gotoxy(pos.x, pos.y);
	cout << "¢Â";
}

void Player::Input()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		pos.y -= 2;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		pos.y += 2;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		pos.x -= 2;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		pos.x += 2;
	Sleep(100);
}
