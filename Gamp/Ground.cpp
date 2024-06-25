#include "Ground.h"

void Ground::UpdateGround()
{
	for (int i = 0; i < vecGround.size(); ++i)
	{
		vecGround[i].life--;
		if (vecGround[i].life == 0) {
			arrMap[vecGround[i].pos.y][vecGround[i].pos.x] = '1';
			vecGround.erase(vecGround.begin() + i);
		}
	}
}
