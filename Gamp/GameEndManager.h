#pragma once
class GameEndManager
{
public:
	bool EndTimer();
	void GameEnd(bool result);
private:
	void EndingAnimation();
	void EndingRenderer(bool result);
public:
	clock_t gameOverStartTimer;
	bool isGameEnd = false;
private:
	int gamePlayTime = 120;
	int currentTimer;
};

