#include<algorithm>
#include "Player.h"
#include "GameLogic.h"

void Player::Render()
{
	Gotoxy(pos.x, pos.y);
	cout << "¢Â";
}

void Player::Input()
{
	if (arrMap[pos.y + 1][pos.x] == '0')
		pos.y += 2;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		pos.y -= 2;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		pos.y += 2;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		pos.x -= 2;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		pos.x += 2;

	pos.x = std::clamp(pos.x, 0, MAP_WIDTH * 2);
	pos.y = std::clamp(pos.y, 0, MAP_HEIGHT - 1);
	Sleep(100);
}

void Player::GroundCheck()
{
	float OnGroundEndTime = clock();
	if ((OnGroundStartTime - OnGroundEndTime) > 1)
	{
		arrMap[pos.y + 1][pos.x] = '0';
	}
}
