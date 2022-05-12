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
	

    auto Menu1 = new Menu({ L"   +   键————增加医护",
  L"   -   键————减少医护",
  L"   H   键————全员核酸",
  L"   O   键————封城封控",
  L"   G   键————集中隔离",
  L"  空格 键————到下一天",
		L"          退格键 返回" },
		{ 16, 16, 16,16,16,14 ,16 },
		{ {600,200}, {600,300}, {600,400},{600,500},{600,600},{600,700},{600,800} },
		{ IntroText ,IntroText ,IntroText ,IntroText,IntroText,IntroText,IntroText }
	);




	TextBar textbarframe({ L"╔════════╗",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"╠════════╣",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",L"╚════════╝" },
	{10,22,22,22,22,22,22,22,10,22,22,22,22,22,22,22,22,22,22,10},
		{ {1540,0},{1540,50},{1540,100},{1540,150},{1540,200},{1540,250 },{1540,300},{1540,350},{1540,400 },{1540,450 },{1540,500 },{1540,550 },{1540, 600},{1540, 650},{1540,700 },{1540,750 },{1540,800 },{1540,850 },{1540,900 },{1540,950 } },
	{MenuText,MenuText,MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText ,MenuText, MenuText, MenuText, MenuText, MenuText },
	textbarinfo
	);
	TextBar EventBar = textbarframe;
	TextBar InfoBar = EventBar;

	point curcusor={11,9};



	while (1)
	{
		auto Menu2 = new Menu({ L"╔════════╗",
	L"║                    ║",L"║                    ║",L"║                    ║",
	L"║                    ║",L"║                    ║",L"║                    ║",L"║                    ║",
	L"╚════════╝" },

			{ 10, 22, 22,22,22,22,22,22,10 },
			{ {520,100}, {520,200}, {520,300}, {520,400},{520,500},{520,600},{520,700},{520,800},{520,900} },
			{ IntroText ,IntroText ,IntroText ,IntroText,IntroText,IntroText,IntroText }
		);
		bool concon = true;
		int state = 2;

		state = Menu1->show(10);//0是游戏，1是介绍，2是菜单，3是退出游戏
		if (state == 1)
		{
			state = Menu1->show(10, 10);
		}
		else if (state == 3) return 0;
		char Operator = 0;
		int finaldate = 0;
		//Map map;
		
		auto MainMap = new Map();

		while (state == 0&&concon)
		{

			if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
				auto ch = _getch();//使用_getch()函数获取按下的键值
				if (ch == 27) { return 0; }//当按下ESC时循环，ESC键的键值时27.
				else if ((ch == 119 || ch == 87) && curcusor.y > 0 && MainMap->logicmap[curcusor.y - 1][curcusor.x] == 1)
				{
					//MainMap->SetColor(curcusor, DefaultCube);
					MainMap->rgbdata[curcusor.y][curcusor.x] = MainMap->rgbrawdata[curcusor.y][curcusor.x];
					curcusor.y--;

				}
				else if ((ch == 115 || ch == 83) && curcusor.y < MainMap->Ifo.ysize - 1 && MainMap->logicmap[curcusor.y + 1][curcusor.x] == 1)
				{
					//MainMap->SetColor(curcusor, DefaultCube);
					MainMap->rgbdata[curcusor.y][curcusor.x] = MainMap->rgbrawdata[curcusor.y][curcusor.x];
					curcusor.y++;
				}
				else if ((ch == 97 || ch == 65) && curcusor.x > 0 && MainMap->logicmap[curcusor.y][curcusor.x - 1] == 1)
				{
					//MainMap->SetColor(curcusor, DefaultCube);
					MainMap->rgbdata[curcusor.y][curcusor.x] = MainMap->rgbrawdata[curcusor.y][curcusor.x];
					curcusor.x--;
				}
				else if ((ch == 100 || ch == 68) && curcusor.x < MainMap->Ifo.xsize - 1 && MainMap->logicmap[curcusor.y][curcusor.x + 1] == 1)
				{
					//MainMap->SetColor(curcusor, DefaultCube);
					MainMap->rgbdata[curcusor.y][curcusor.x] = MainMap->rgbrawdata[curcusor.y][curcusor.x];
					curcusor.x++;
				}

				if (ch == 43) Operator = '+';
				else if (ch == 45) Operator = '-';
				else if (ch == 111 || ch == 79) Operator = 'o';
				else if (ch == 103 || ch == 71) Operator = 'g';
				else if (ch == 104 || ch == 72)Operator = 'h';

				if (ch == 32) Operator = ' ';
				if (ch == 8)
				{
					state = 2;
					break;
				}

			}
			MainMap->area.Operation(curcusor.x + curcusor.y * 23, Operator);
			//MainMap->area.area_arr[curcusor.x * curcusor.y]->getKnown_Infectious();
			MainMap->SetColor(curcusor, Cube1);
			if (Operator == ' ')
			{
				concon=MainMap->GenerallyUpdate();
			}


			InfoBar.SetTextbar(MainMap->area.outtext_im(curcusor.x + curcusor.y * 23), getnum(MainMap->area.outtext_im(curcusor.x + curcusor.y*23)), InfoPoints, InfoRGB, textinfo2);
			EventBar.SetTextbar(MainMap->area.outevent(), getnum(MainMap->area.outevent()), EventPoints, EventRGB, textinfo);
			render.RenderMap(mapinfo, L"    ", 4, MainMap->rgbdata);
			render.RenderTextbar(textbarframe, 1);
			render.RenderTextbar(EventBar, 2);
			render.RenderTextbar(InfoBar, 2);
			render.Render(appinfo);
			Operator = 'a';
		}
		Menu2->menutext = { L"你坚持了" + to_wstring(MainMap->area.date) + L"天" };
		Menu2->points = { {650,400} };
		Menu2->rgbdatas = { IntroText };
		Menu2->textsize = getnum(Menu2->menutext);

		if (concon == false)
		{
			state = Menu2->show(10, 10);
			concon = true;
		}
		delete Menu2;
		delete MainMap;
	}


	return 0;

}