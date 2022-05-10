#include"Map.h"
#include"RenderEngine.h"
#include<iostream>
#include<conio.h>
#include"Menu.h"
#include"TextBar.h"
int main()
{
//窗口最大化
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);    //获得控制台句柄
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//获得控制台最大坐标，坐标以字符数为单位
	NewSize.X -= 1;
	NewSize.Y -= 1;    //可以不加，不加时显示滚动条
	SetConsoleScreenBufferSize(HOUT, NewSize); //设置控制台缓冲区大小
	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea);    //设置控制台大小
	//控制台已经最大化，但是初始位置不在屏幕左上角，添加如下代码
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
//窗口最大化

//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = true; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
//隐藏光标


	Renderer render(3000, 3000);
	Map map;
	Menu menu;
	TextBar textbarframe({ L"╔════════╗",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"╠════════╣",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"╚════════╝" },
	{10,22,22,22,22,22,22,22,10,22,22,22,22,22,22,22,22,22,22,10},
		{ {1540,0},{1540,50},{1540,100},{1540,150},{1540,200},{1540,250 },{1540,300},{1540,350},{1540,400 },{1540,450 },{1540,500 },{1540,550 },{1540, 600},{1540, 650},{1540,700 },{1540,750 },{1540,800 },{1540,850 },{1540,900 },{1540,950 } },
	{MenuText,MenuText,MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText ,MenuText, MenuText, MenuText, MenuText, MenuText },
	textbarinfo
	);


	TextBar textbar({ L"A处有" },
		{ 3 },
		{ {1575,100} },
		{  text1 },
		textinfo
	);


	point curcusor;
	curcusor.x = 9;
	curcusor.y = 9;

	int state = menu.show(10);
	char Operator = 0;


	while (state == 0)
	{

		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			auto ch = _getch();//使用_getch()函数获取按下的键值
			if (ch == 27) { return 0; }//当按下ESC时循环，ESC键的键值时27.
			else if ((ch == 119 ||ch==87)&& curcusor.y > 0 && map.logicmap[curcusor.y - 1][curcusor.x] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y--;
				
			}
			else if ((ch == 115 ||ch==83)&& curcusor.y < map.Ifo.ysize-1 && map.logicmap[curcusor.y + 1][curcusor.x] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y++;
			}
			else if ((ch == 97||ch== 65)&& curcusor.x > 0 && map.logicmap[curcusor.y][curcusor.x - 1] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x--;
			}
			else if ((ch == 100||ch== 68)&& curcusor.x < map.Ifo.xsize - 1&&map.logicmap[curcusor.y][curcusor.x + 1]==1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x++;
			}

			if (ch == 43) Operator = '+';
			else if (ch == 45) Operator = '-';
			else if (ch == 111 || ch == 79) Operator = 'o';
			else if (ch == 103 || ch == 71) Operator = 'g';
			else if (ch == 104 || ch == 72)Operator = 'h';

			if (ch == 32) Operator = ' ';

		}
		map.area.Operation(curcusor.x * curcusor.y, Operator);
		map.area.area_arr[curcusor.x*curcusor.y]->getKnown_Infectious();
		map.SetColor(curcusor, Cube1);
		if (Operator == ' ')
		{
			map.area.GenerallyUpdate();
		}
		render.RenderMap(mapinfo, L"    ", 4, map.rgbdata); 
		render.RenderTextbar(textbar, 2);
//		render.RenderTextbar(textbarframe, 1);
		render.Render(appinfo);
		Operator = 'a';
	}
	return 0;

}