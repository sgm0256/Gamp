#include<iostream>
#include<fcntl.h>
#include<io.h>
#include "TitleScene.h"
#include "console.h"
//#include<stdlib.h>

void TitleRenderer()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	██████╗  ██████╗  ██████╗ ███╗   ███╗     ██╗     ██████╗ ██╗      █████╗ ███████╗████████╗ " << endl;
	wcout << L"	██╔══██╗██╔═══██╗██╔═══██╗████╗ ████║     ██║     ██╔══██╗██║     ██╔══██╗██╔════╝╚══██╔══╝ " << endl;
	wcout << L"	██████╔╝██║   ██║██║   ██║██╔████╔██║  ████████╗  ██████╔╝██║     ███████║███████╗   ██║    " << endl;
	wcout << L"	██╔══██╗██║   ██║██║   ██║██║╚██╔╝██║  ██╔═██╔═╝  ██╔══██╗██║     ██╔══██║╚════██║   ██║    " << endl;
	wcout << L"	██████╔╝╚██████╔╝╚██████╔╝██║ ╚═╝ ██║  ██████║    ██████╔╝███████╗██║  ██║███████║   ██║    " << endl;
	wcout << L"	╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝  ╚═════╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝    " << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	
}

bool TitleScene()
{
	system("mode con:cols=107 lines=22");
	LockResize();
	while (true)
	{
		system("cls");
		TitleRenderer();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
		case MENU::INFO:
			InfoRenderer();
			break;
		case MENU::QUIT:
			system("cls");
			exit(0);
			return false;
		}
	}
}

MENU MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2.25f;  // 2.5
	int y = Resolution.Y / 2.5f;// 3
	int originy = y;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "게임 종료";
	while (true)
	{
		KEY eKey = KeyControllor();
		switch (eKey)
		{
		case KEY::UP:
			if (originy < y)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);


				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (originy + 2 > y)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::SPACE:
		{
			if (y == originy)
				return MENU::START;
			else if (y == originy + 1)
				return MENU::INFO;
			else if (y == originy + 2)
				return MENU::QUIT;
		}
		break;
		}
	}
}

KEY KeyControllor()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) // 2
	{
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) // 2
	{
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) // 2
	{
		Sleep(50);
		return KEY::SPACE;
	}
	return KEY::FALL;
}

void EnterAnimation()
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
	system("cls");
}

void InfoRenderer()
{

	system("cls");

	cout << "남은 시간이 다 될때까지 적들로부터 살아남으세요." << endl;
	cout << "멈춰있으면 발판이 부서지니 계속 움직이세요." << endl;
	cout << "폭탄의 범위는 30초 마다 1단계씩 증가하여 최대 3단계까지 증가합니다." << endl;
	cout << "적에게 닿거나 맵의 바닥으로 떨어지면 게임이 끝납니다." << endl << endl;
	cout << "화살표키 -> 이동" << endl;
	cout << "스페이스바 -> 폭탄 설치" << endl;

	while (true)
	{
		if (KeyControllor() == KEY::SPACE)
		{
			break;
		}
	}
}
