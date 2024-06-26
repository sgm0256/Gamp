#pragma once
#include "Ground.h"
#include "Player.h"
#include "EnemySpawn.h"
class Object
{
public:
	Ground m_ground;
	Player m_player;
	EnemySpawn enmeySpawn;
public:
	static Object* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Object;
		return m_pInst;
	}
	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}
private:
	static Object* m_pInst;
};

