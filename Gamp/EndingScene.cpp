#include "EndingScene.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>

void EndingScene::EndingAnimation(bool result)
{
	COORD Resolution = GetConsoleResolution();
	int width = Resolution.X;
	int height = Resolution.Y;
	int anitime = 10;
	system("cls");

	SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
	for (int i = 0; i < width / 2; ++i)
	{
		for (int j = 0; j < height; j += 1)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	for (int i = 0; i < width / 2; ++i)
	{
		for (int j = 0; j < height; j += 1)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		Sleep(anitime);
	}
	system("cls");
	EndingRenderer(result);
}

void EndingScene::EndingRenderer(bool result)
{
	if (result)
	{
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

		wcout << L"	 ██████╗  █████╗ ███╗   ███╗███████╗	 ██████╗██╗     ███████╗ █████╗ ██████╗  " << endl;
		wcout << L"	██╔════╝ ██╔══██╗████╗ ████║██╔════╝	██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗ " << endl;
		wcout << L"	██║  ███╗███████║██╔████╔██║█████╗  	██║     ██║     █████╗  ███████║██████╔╝ " << endl;
		wcout << L"	██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  	██║     ██║     ██╔══╝  ██╔══██║██╔══██╗ " << endl;
		wcout << L"	╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗	╚██████╗███████╗███████╗██║  ██║██║  ██║ " << endl;
		wcout << L"	╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ 	╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝  " << endl;
		int curmode = _setmode(_fileno(stdout), prevmode);
	}
	else
	{
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

		wcout << L"	 ██████╗  █████╗ ███╗   ███╗███████╗      ██████╗ ██╗   ██╗███████╗██████╗  " << endl;
		wcout << L"	██╔════╝ ██╔══██╗████╗ ████║██╔════╝     ██╔═══██╗██║   ██║██╔════╝██╔══██╗ " << endl;
		wcout << L"	██║  ███╗███████║██╔████╔██║█████╗       ██║   ██║██║   ██║█████╗  ██████╔╝ " << endl;
		wcout << L"	██║   ██║██╔══██║██║╚██╔╝██║██╔══╝       ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗ " << endl;
		wcout << L"	╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗     ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║ " << endl;
		wcout << L"	╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝      ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝  " << endl;
		int curmode = _setmode(_fileno(stdout), prevmode);
	}



}
