#include<iostream>
#include<fcntl.h>
#include<io.h>
#include "TitleScene.h"
#include "console.h"

void TitleRenderer()
{

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"	██████╗  ██████╗  ██████╗ ███╗   ███╗       ██╗       ██████╗ ██╗      █████╗ ███████╗████████╗" << endl;
	wcout << L"	██╔══██╗██╔═══██╗██╔═══██╗████╗ ████║       ██║       ██╔══██╗██║     ██╔══██╗██╔════╝╚══██╔══╝" << endl;
	wcout << L"	██████╔╝██║   ██║██║   ██║██╔████╔██║    ████████╗    ██████╔╝██║     ███████║███████╗   ██║   " << endl;
	wcout << L"	██╔══██╗██║   ██║██║   ██║██║╚██╔╝██║    ██╔═██╔═╝    ██╔══██╗██║     ██╔══██║╚════██║   ██║   " << endl;
	wcout << L"	██████╔╝╚██████╔╝╚██████╔╝██║ ╚═╝ ██║    ██████║      ██████╔╝███████╗██║  ██║███████║   ██║   " << endl;
	wcout << L"	╚═════╝  ╚═════╝  ╚═════╝ ╚═╝     ╚═╝    ╚═════╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝   " << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	
}
