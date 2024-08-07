#include<algorithm>
#include "Player.h"
#include "ObjectManager.h"

void Player::Render()
{
	Gotoxy(pos.x, pos.y);
	cout << "��";
}

void Player::Update()
{
	MoveInput();
	BombInput();
}

void Player::MoveInput()
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

	if (inputPos.x != 0 || inputPos.y != 0)
		if (ObjectManager::GetInst()->m_ground.arrMap[pos.y - 1][pos.x / 2] != (char)OBJ_TYPE::Air)
			ObjectManager::GetInst()->m_ground.onGroundStartTime = clock();

	Move(inputPos);
	Sleep(100);
}

void Player::BombInput()
{
	clock_t bombInputTime = clock();

	clock_t bombTimer = (bombInputTime - lastBombTime) / CLOCKS_PER_SEC;

	if ((bombInputTime - lastBombTime) / CLOCKS_PER_SEC > 1)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8000) 
		{
			ObjectManager::GetInst()->m_bomb.SpawnBomb(pos);
			lastBombTime = clock();
		}
	}

}

void Player::Move(POS _pos)
{
	pos += _pos;

	pos.x = std::clamp(pos.x, 0, (MAP_WIDTH - 1) * 2);
	pos.y = std::clamp(pos.y, 0, MAP_HEIGHT - 2);


	if (ObjectManager::GetInst()->m_ground.arrMap[pos.y][pos.x / 2] == (char)OBJ_TYPE::Enemy
		|| (ObjectManager::GetInst()->m_ground.arrMap[pos.y + 1][pos.x / 2]
			== (char)OBJ_TYPE::Air && pos.y == MAP_HEIGHT-2))
		ObjectManager::GetInst()->m_GameEndManager.GameEnd(false);

	if (ObjectManager::GetInst()->m_ground.arrMap[pos.y + 1][pos.x / 2] == (char)OBJ_TYPE::Air)
		pos += {0, 2};
}