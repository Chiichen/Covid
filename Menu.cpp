#include"Menu.h"
using namespace std;

void SetFont(int size = 30) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL; //字体粗细 FW_BOLD
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode con cols=1920 lines=540");
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
}


Menu::Menu(vector<wstring>strlist,vector<int> sizelist, vector<point>points,vector<RGBData>rgbdatas)
	:renderer(3000, 3000), 
	menutext(strlist),
	textsize(sizelist),
	points(points),
	rgbdatas(rgbdatas)
{
	
}


Menu::~Menu()
{
}

int Menu::show(int a,int b)
{
	int curpos = 0;
	int state = 1;
	while (1)
	{
		renderer.RenderText(menuinfo, points, menutext, textsize, rgbdatas, 1);
		renderer.Render(appinfo);
		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			auto ch = _getch();//使用_getch()函数获取按下的键值
			if (ch == 8)
			{
				return 2;
			}
		}

	}

	
	return state;
}

int Menu::show(int a)
{

	HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
	COORD coord = { 0,0 };
	//双缓冲处理显示
	DWORD bytes = 0;
	auto m1 = new char[540][1920];
	auto m2 = new char[540][1920];
	auto m3 = new char[540][1920];
	SetConsoleActiveScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE));
	SetFont(1);
	int cnt = 0;
	int idx = 0;
	ifstream ifs;
	ifs.open("file.txt", ios::in);
	char c;
	while ((c = ifs.get()) != EOF)
	{
		if (c != '\n')
		{
		m1[idx][cnt++] = c;
		}
	else 
		{
		cnt = 0;
		idx++;
		}
	}
	ifs.close();


	cnt = 0;
	idx = 0;
	ifs.open("file1.txt", ios::in);
	while ((c = ifs.get()) != EOF)
	{
		if (c != '\n')
		{
			m2[idx][cnt++] = c;
		}
		else
		{
			cnt = 0;
			idx++;
		}
	}
	ifs.close();

	cnt = 0;
	idx = 0;
	ifs.open("file2.txt", ios::in);
	while ((c = ifs.get()) != EOF)
	{
		if (c != '\n')
		{
			m3[idx][cnt++] = c;
		}
		else
		{
			cnt = 0;
			idx++;
		}
	}
	ifs.close();


		hOutBuf = CreateConsoleScreenBuffer(
			GENERIC_WRITE,//定义进程可以往缓冲区写数据
			FILE_SHARE_WRITE,//定义缓冲区可共享写权限
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL
		);
		hOutput = CreateConsoleScreenBuffer(
			GENERIC_WRITE,//定义进程可以往缓冲区写数据
			FILE_SHARE_WRITE,//定义缓冲区可共享写权限
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL
		);
		CONSOLE_CURSOR_INFO cci;
		cci.bVisible = 0;
		cci.dwSize = 1;
		SetConsoleCursorInfo(hOutput, &cci);
		SetConsoleCursorInfo(hOutBuf, &cci);

		int state = 0;
		int curpos = 0;

		while (1)
		{
			if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
				auto ch = _getch();//使用_getch()函数获取按下的键值
				if (ch == 13)
				{
					return state;
				}
				else if (ch == 119 && curpos == 1)
				{
					curpos--;
					state--;
				}
				else if (ch == 115 && curpos == 0)
				{
					curpos++;
					state++;
				}
				else if (ch == 8) return 3;
			}
			if (curpos == 0)
			{
				for (int i = 0; i < 540; i++)
				{
					coord.Y = i;
					WriteConsoleOutputCharacterA(hOutBuf, m2[i], sizeof(m2[i]), coord, &bytes);
				}
				SetConsoleActiveScreenBuffer(hOutBuf);
				//Sleep(50);
				for (int i = 0; i < 540; i++)
				{
					coord.Y = i;
					WriteConsoleOutputCharacterA(hOutput, m2[i], sizeof(m2[i]), coord, &bytes);
				}
				SetConsoleActiveScreenBuffer(hOutput);
			}
			else {
				for (int i = 0; i < 540; i++)
				{
					coord.Y = i;
					WriteConsoleOutputCharacterA(hOutBuf, m3[i], sizeof(m3[i]), coord, &bytes);
				}
				SetConsoleActiveScreenBuffer(hOutBuf);
				//Sleep(50);
				for (int i = 0; i < 540; i++)
				{
					coord.Y = i;
					WriteConsoleOutputCharacterA(hOutput, m3[i], sizeof(m3[i]), coord, &bytes);
				}
				SetConsoleActiveScreenBuffer(hOutput);
			}
		}

	
	
	};

   
