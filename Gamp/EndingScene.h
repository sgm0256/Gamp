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
private:
	int gamePlayTime = 10;
	int currentTimer;
};

