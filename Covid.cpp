//#include<random>
//#include<Windows.h>
//#include<queue>
//#include <conio.h>
//#include"Map"
//#include<iostream>
//#include<string>
//using namespace std;
//#pragma warning(disable:4996)
//#define KEY_DOWN(vk_code) GetAsyncKeyState(vk_code)&0x8000?1:0
//
//HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
//COORD coord = { 0,0 };
////双缓冲处理显示
//DWORD bytes = 0;
//char m[15][300];
//using namespace std;
//struct point {
//	int x = 0;
//	int y = 0;
//};
//int random_unint(unsigned int min, unsigned int max)
//{
//	std::random_device rd;
//	static std::default_random_engine e(rd());
//	std::uniform_int_distribution<int> u(min, max);
//	return u(e);
//}
//
//double random_unint(double min, double max)
//{
//	std::random_device rd;
//	static std::default_random_engine e(rd());
//	std::uniform_real_distribution<double> u(min, max);
//	return u(e);
//}
//
//
///*注意: 在Textout函数里x,y是以左上角为原点，从左往右为x，从上往下为y，与数组xy刚好相反，这里传入的参数是横x纵y；
//        x,y是输出字符坐标，bufferDC是内存创建的DC，font是字体属性
//		BufferDC必须在传入前就有画布Bitmap
//*/
////bool RenderCharToBuffer(int x, int y, HDC BufferDC, HFONT font, wstring str, int size)
////{
////	//HWND hWnd = GetConsoleWindow();
////	//HDC hdc = GetDC(hWnd);
////	auto tempfont = font;
////	SelectObject(BufferDC, tempfont);
////	SetBkColor(BufferDC, 0x000000);
////	SetTextColor(BufferDC, RGB(100, 149, 237));
////	LPCWSTR str2 = str.c_str();
////	TextOut(BufferDC, x, y, str2, size);
////	DeleteObject(tempfont);
////	//ValidateRect(hWnd, 0);
////
////	return 1;
////}
////
////void RendrFromDC(HDC OutDC, HDC BufferDC, int width, int height, HBITMAP Hbmp)//BufferDC必须有一个画布Hbmp,作为参数传入防止忘记析构
////{
////	
////	BitBlt(OutDC, 0, 0, width, height, BufferDC, 0, 0, SRCCOPY);
////	DeleteObject(Hbmp);
////}
//
//template<int maxx, int maxy>
//void bfsa(int (& a)[maxx][maxy], double prameter)
//{
//	const int b[4] = { 0,0,maxx-1,maxx-1 };
//	const int c[4] = { 0,maxy-1,0,maxy-1};
//	const int xx[5] = { 0,0,0,1,-1 };
//	const int yy[5] = { 0,1,-1,0,0 };
//	queue<point> que;
//	for (int i = 0; i < 4; i++)
//	{
//		point p;
//		p.x = b[i], p.y = c[i];
//		que.push(p);
//		bool flag = true;
//		while (!que.empty())
//		{
//			point cur = que.front();
//			que.pop();
//			for (int i = 0; i < 5; i++)
//			{
//				cur.x += xx[i]; cur.y += yy[i];
//				if (cur.x >= 0 && cur.x < maxx && cur.y >= 0 && cur.y < maxy && a[cur.x][cur.y] == 1 && (random_unint((double)0, (double)1) <= prameter||flag))
//				{
//					flag = false;
//					a[cur.x][cur.y] = 0;
//					que.push(cur);
//				}
//			}
//		}
//		return;
//	}
//}
//
//
//
//
//
//int main()
//{
//	hOutBuf = CreateConsoleScreenBuffer(
//		GENERIC_WRITE,//定义进程可以往缓冲区写数据
//		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
//		NULL,
//		CONSOLE_TEXTMODE_BUFFER,
//		NULL
//	);
//	hOutput = CreateConsoleScreenBuffer(
//		GENERIC_WRITE,//定义进程可以往缓冲区写数据
//		FILE_SHARE_WRITE,//定义缓冲区可共享写权限
//		NULL,
//		CONSOLE_TEXTMODE_BUFFER,
//		NULL
//	);
//	HWND hWnd = GetConsoleWindow();
//	HDC hdc = GetDC(hWnd);
//	HDC MemDC = CreateCompatibleDC(hdc);
//	auto Hbmp = CreateCompatibleBitmap(hdc,1000,1000);
//	CONSOLE_CURSOR_INFO cci;
//	cci.bVisible = 0;
//	cci.dwSize = 1;
//	SetConsoleCursorInfo(hOutput, &cci);
//	SetConsoleCursorInfo(hOutBuf, &cci);
//
//
//
//	int nPlayerRow = 1;//定义玩家的行
//	int nPlayerCol = 1;//定义玩家的列
//	int nMenuState = 0;//用于控制箭头
//	int nGameState = 0;//用于控制界面
//	int nRowX = 0;
//	int nRowY = 0;
//	int arrMap[15][20] = {
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//	 { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
//	bfsa(arrMap,0.7);
//
//	while (true)//用于进行循环刷新
//	{
//		if (0 == nGameState)//如果界面的值为0，当前为菜单界面
//		{
//			char key;
//			while (!_kbhit()) {}
//			key = getch();
//			system("cls");
//			if (key == 's')//检测是否按下向下箭头
//			{
//				nMenuState++;//控制箭头的值增加1
//				if (nMenuState > 2)//因为菜单一共只有三个选项，所以当控制箭头的数量大于2时，重新赋值为0，返回到箭头的初始位置
//				{
//					nMenuState = 0;
//				}
//			}
//
//			else if (key == 'w')//同上
//			{
//				nMenuState--;
//				if (nMenuState < 0)
//				{
//					nMenuState = 2;
//				}
//			}
//
//			if (key == 'b')//检测是否按下Enter键
//			{
//
//				if (0 == nMenuState)//如果当前箭头位置为游戏开始
//				{
//					nGameState = 1;//设置界面的值为1，从菜单界面切换为地图界面
//				}
//				else if (1 == nMenuState)//如果当前箭头位置为游戏设置
//				{
//					nGameState = 2;//设置界面的值为2，从菜单界面切换为游戏设置界面
//				}
//				else if (2 == nMenuState) {
//					nGameState = 3;
//				}
//			}
//			//画出菜单
//			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;//因为放在while（true）里面，所以这里会一直运行
//			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
//
//			if (0 == nMenuState)//画箭头位置
//			{
//				cout << "■■■        ->游戏开始          ■■■" << endl;
//				cout << "■■■          游戏设置          ■■■" << endl;
//				cout << "■■■          游戏退出          ■■■" << endl;
//			}
//			else if (1 == nMenuState)
//			{
//				cout << "■■■          游戏开始          ■■■" << endl;
//				cout << "■■■        ->游戏设置          ■■■" << endl;
//				cout << "■■■          游戏退出          ■■■" << endl;
//			}
//			else if (2 == nMenuState) {
//				cout << "■■■          游戏开始          ■■■" << endl;
//				cout << "■■■          游戏设置          ■■■" << endl;
//				cout << "■■■        ->游戏退出          ■■■" << endl;
//			}
//			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
//			cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
//
//		}
//
//
//
//		//地图界面
//		if (1 == nGameState)
//		{
//			char key;
//			while (!_kbhit()) {}
//			key = getch();
//			//在玩家移动前对坐标进行备份，把坐标赋给值的变量
//			nRowX = nPlayerRow;//nPlayerRow = 3; nPlayerCol = 3
//			nRowY = nPlayerCol;
//
//
//			//数据更新，要在渲染的前面
//			//设置按键让小人移动
//			if (key == 'w')
//			{
//				nPlayerRow--;
//			}
//			else if (key == 's')
//			{
//				nPlayerRow++;
//			}
//			else if (key == 'a')
//			{
//				nPlayerCol--;
//			}
//			else if (key == 'd')
//			{
//				nPlayerCol++;
//			}
//
//
//			//检测玩家是否撞墙
//			if (1 == arrMap[nPlayerRow][nPlayerCol] || 2 == arrMap[nPlayerRow][nPlayerCol]) //当玩家的值为1
//			{
//				nPlayerRow = nRowX;//把现在玩家的值赋值给之前的索引,nPlayerRow = 3,位置不变
//				nPlayerCol = nRowY;
//			}
//			//二维数组的遍历
//
//			for (int i = 0; i < 15; i++) //行数为15
//			{
//				for (int j = 0; j < 20; j++)//列数为20
//				{
//					////判断第i行第j列应该画什么
//					//if (1 == arrMap[i][j])//把数字为1的地方替换为■，作为墙壁
//					//{
//					//	//cout << "■"
//					//	strncpy(m[i] + j * sizeof("   ") * 2 / 3, "   ", sizeof("   "));
//					//}
//					//if (2 == arrMap[i][j])//把数字为2的地方替换为●，作为箱子
//					//{
//					//	//cout << "●";
//					//	strncpy(m[i] + j * sizeof("■") * 2 / 3, "■", sizeof("■"));
//					//}
//					//else if (i == nPlayerRow && j == nPlayerCol)//如果当前的行为玩家的行，当前的列为玩家的列（当前的位置为玩家的位置）
//					//{
//					//	//cout << "人";
//					//	strncpy(m[i] + j * sizeof("●") * 2 / 3, "●", sizeof("●"));
//					//}
//					//else if (0 == arrMap[i][j])
//					//{
//					//	//cout << "  ";//数字为0的地方设为空格
//					//	strncpy(m[i] + j * sizeof("■") * 2 / 3, "■", sizeof("■"));
//					//}
//
//					if (1 == arrMap[i][j])//把数字为1的地方替换为■，作为墙壁
//					{
//						//cout << "■"
//						RenderCharToBuffer(j * 60, i * 60, MemDC, font1, L"   ",4); 
//					}
//					else if (i == nPlayerRow && j == nPlayerCol)//如果当前的行为玩家的行，当前的列为玩家的列（当前的位置为玩家的位置）
//					{
//						//strncpy(m[i] + j * sizeof("●") * 2 / 3, "●", sizeof("●"));
//						RenderCharToBuffer(j * 60, i * 60, MemDC, font1, L" ● ",4);
//					}
//					else if (0 == arrMap[i][j])
//					{
//						//cout << "  ";//数字为0的地方设为空格
//						RenderCharToBuffer(j * 60, i * 60, MemDC, font1, L" ■ ",4);
//					}
//
//				}
//				cout << 1 << endl;
//			}
//			cout << 1 << endl;
//			Sleep(50);
//			auto tempHbmp = Hbmp;
//			RendrFromDC(hdc, MemDC, 100, 100, tempHbmp);
//			//for (int i = 0; i < 15; i++)
//			//{
//			//	coord.Y = i;
//			//	WriteConsoleOutputCharacterA(hOutBuf, m[i], sizeof(m[i]), coord, &bytes);
//			//}
//			//SetConsoleActiveScreenBuffer(hOutBuf);
//			////Sleep(50);
//			//for (int i = 0; i < 15; i++)
//			//{
//			//	coord.Y = i;
//			//	WriteConsoleOutputCharacterA(hOutput, m[i], sizeof(m[i]), coord, &bytes);
//			//}
//			//SetConsoleActiveScreenBuffer(hOutput);
//		}
//
//		Sleep(10);
//	}
//	system("pause");
//	return 0;
//
//
//}