#include<io.h>
#include<fcntl.h>
#include "console.h"
#include "GameEndManager.h"
#include "define.h";

bool GameEndManager::EndTimer()
{
	clock_t gameOverEndTimer = clock();

	GotoPos(MAP_WIDTH * 2 + 5, 1);
	currentTimer = gamePlayTime - (gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC;
	cout << "남은 시간: " << currentTimer / 60 << " : " << currentTimer % 60 << " ";

	if ((gameOverEndTimer - gameOverStartTimer) / CLOCKS_PER_SEC < gamePlayTime)
		return true;
	else
	{
		GameEnd(true);
		return false;
	}
}

void GameEndManager::GameEnd(bool result)
{
	EndingAnimation();
	EndingRenderer(result);
	isGameEnd = true;
}

void GameEndManager::EndingAnimation()
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int anitime = 10;
	system("cls");

	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	for (int i = 0; i <= width / 2; ++i)
	{
		for (int j = 0; j < height; j += 1)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	for (int i = 0; i <= width / 2; ++i)
	{
		for (int j = 0; j < height; j += 1)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
}

void GameEndManager::EndingRenderer(bool result)
{
	system("cls");

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	if (result)
	{

		wcout << L"		 ██████╗  █████╗ ███╗   ███╗███████╗	 ██████╗██╗     ███████╗ █████╗ ██████╗  " << endl;
		wcout << L"		██╔════╝ ██╔══██╗████╗ ████║██╔════╝	██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗ " << endl;
		wcout << L"		██║  ███╗███████║██╔████╔██║█████╗  	██║     ██║     █████╗  ███████║██████╔╝ " << endl;
		wcout << L"		██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  	██║     ██║     ██╔══╝  ██╔══██║██╔══██╗ " << endl;
		wcout << L"		╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗	╚██████╗███████╗███████╗██║  ██║██║  ██║ " << endl;
		wcout << L"		╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ 	╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝  " << endl;
	}
	else
	{
		wcout << L"		 ██████╗  █████╗ ███╗   ███╗███████╗      ██████╗ ██╗   ██╗███████╗██████╗  " << endl;
		wcout << L"		██╔════╝ ██╔══██╗████╗ ████║██╔════╝     ██╔═══██╗██║   ██║██╔════╝██╔══██╗ " << endl;
		wcout << L"		██║  ███╗███████║██╔████╔██║█████╗       ██║   ██║██║   ██║█████╗  ██████╔╝ " << endl;
		wcout << L"		██║   ██║██╔══██║██║╚██╔╝██║██╔══╝       ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗ " << endl;
		wcout << L"		╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗     ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║ " << endl;
		wcout << L"		╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝      ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝  " << endl;
	}
	int curmode = _setmode(_fileno(stdout), prevmode);

	cout << "\n\n" << "아무키나 눌러 게임을 종료...";
}
