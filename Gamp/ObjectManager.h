#pragma once
#include "Ground.h"
#include "Player.h"
#include "Bomb.h"
#include "Enemy.h"
#include "GameEndManager.h"

class ObjectManager
{
public:
	Enemy m_enemy;
	Bomb m_bomb;
	Ground m_ground;
	Player m_player;
	GameEndManager m_GameEndManager;
public:
	static ObjectManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new ObjectManager;
		return m_pInst;
	}
	static void DestroyInst() {
		SAFE_DELETE(m_pInst);
	}
private:
	static ObjectManager* m_pInst;
};
