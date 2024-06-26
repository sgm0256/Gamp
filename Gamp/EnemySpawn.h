#pragma once
#include <vector>
#include "Enemy.h"
#include<list>

class EnemySpawn
{
public:
	void SpawnEnemy();
	std::list<Enemy> eneymContainerList;

	void EnemysRender(Player player)
	{
		for (auto e : eneymContainerList)
		{
			e.EnemyRnderer(player);
		}
	}

	


};

