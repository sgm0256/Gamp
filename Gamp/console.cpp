#include<Windows.h>
#include "console.h"

void FullScreen()
{
	//SetConsoleDisplayMode
	//(GetStdHandle(STD_OUTPUT_HANDLE),
	//	CONSOLE_FULLSCREEN_MODE, NULL);
	ShowWindow(GetConsoleWindow(),
		SW_MAXIMIZE);
	//::SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN,
	//	VK_RETURN, 0x20000000);
}

void Gotoxy(int _x, int _y)
{
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ�� ���� ����ü.
	COORD Cur = {_x, _y}; // *2�� �ڿ��������������.
	// �ܼ� Ŀ���� ��ġ�� ���� �̵���Ű�� �Լ�.
	SetConsoleCursorPosition(hOut, Cur);
}

BOOL GotoPos(int _x, int _y)
{
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ�� ���� ����ü.
	COORD Cur = { _x, _y }; // *2�� �ڿ��������������.
	// �ܼ� Ŀ���� ��ġ�� ���� �̵���Ű�� �Լ�.
	return SetConsoleCursorPosition(hOut, Cur);
}

COORD CursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
	,&Buf);
	return Buf.dwCursorPosition;
}

void SetCursorVis(bool _vis, DWORD _size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = _vis; // on, off
	curinfo.dwSize = _size; // 1~100
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE)
	,&curinfo);
}

void SetColor(int _textcolor, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
	,(_bgcolor << 4) | _textcolor);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &Buf);
	int color = Buf.wAttributes & 0xf; 
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;// &~WS_CAPTION;
		SetWindowLong(console, GWL_STYLE, style);
	}
}
COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE)
		, &info);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}

void SetFontSize(UINT _weight, UINT _sizex, UINT _sizey)
{
	//����, ������ ũ�� ����
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hOut, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizex;
	font.dwFontSize.Y = _sizey;
	SetCurrentConsoleFontEx(hOut, false, &font);
}
