#pragma once

const int MAP_WIDTH = 21;
const int MAP_HEIGHT = 20;

class GameLogic
{
private:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
public:
	void Init();
	void Render();
};