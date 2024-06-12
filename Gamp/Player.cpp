#include "Player.h"
#include "console.h"

void Player::Render()
{
	Gotoxy(pos.x, pos.y);
	cout << "¥î";
}
