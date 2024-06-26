#include "Enemy.h"
#include "console.h"

void Enemy::EnemyRnderer(Player player)
{
	float xPos = player.pos.x - pos.x;
	float yPos = player.pos.y - pos.y;
	xPos > 0 ? xPos =1 : xPos= -1;
	yPos > 0 ? yPos =2 : yPos= -2;
	Gotoxy(pos.x += xPos, pos.y += yPos);
	cout << "£À";
	
}
