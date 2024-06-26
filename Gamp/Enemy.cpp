#include "Enemy.h"
#include "console.h"

Enemy::Enemy(POS pos)
{
	this->pos = pos;
}

void Enemy::EnemyRnderer(Player player)
{
	Gotoxy(40, 25);
	cout << pos.x << " " << pos.y;
	float xPos = player.pos.x - pos.x;
	float yPos = player.pos.y - pos.y;
	pos += {
		xPos > 0 ? 1 : -1,
			yPos > 0 ? 2 : -2
	};
	/*xPos = xPos > 0 ? 1 : -1;
	yPos = yPos > 0 ? 2 : -2;*/
	Gotoxy(pos.x, pos.y);
	//Sleep(100);
	cout << "£À";

}
