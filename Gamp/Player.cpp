#include<algorithm>
#include "Player.h"

void Player::Render()
{
	Gotoxy(pos.x, pos.y);
	cout << "¢Â";
}

void Player::Input()
{
	POS inputPos = { 0,0 };

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		inputPos.y -= 2;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		inputPos.y += 2;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		inputPos.x -= 2;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		inputPos.x += 2;

	Move(inputPos);
	Sleep(100);
}

void Player::Move(POS _pos)
{
	pos += _pos;

	pos.x = std::clamp(pos.x, 0, (MAP_WIDTH - 1) * 2);
	pos.y = std::clamp(pos.y, 0, MAP_HEIGHT - 2);
}