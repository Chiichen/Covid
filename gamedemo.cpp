#include"Map.h"
#include"RenderEngine.h"
#include<iostream>
#include<conio.h>
#include"Menu.h"
#include"TextBar.h"
int main()
{
//�������
	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);    //��ÿ���̨���
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//��ÿ���̨������꣬�������ַ���Ϊ��λ
	NewSize.X -= 1;
	NewSize.Y -= 1;    //���Բ��ӣ�����ʱ��ʾ������
	SetConsoleScreenBufferSize(HOUT, NewSize); //���ÿ���̨��������С
	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea);    //���ÿ���̨��С
	//����̨�Ѿ���󻯣����ǳ�ʼλ�ò�����Ļ���Ͻǣ�������´���
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
//�������

//���ع��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = true; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
//���ع��


	Renderer render(3000, 3000);
	Map map;
	Menu menu;
	TextBar textbarframe({ L"�X�T�T�T�T�T�T�T�T�[",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�d�T�T�T�T�T�T�T�T�g",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�U                    �U",L"�^�T�T�T�T�T�T�T�T�a" },
	{10,22,22,22,22,22,22,22,10,22,22,22,22,22,22,22,22,22,22,10},
		{ {1540,0},{1540,50},{1540,100},{1540,150},{1540,200},{1540,250 },{1540,300},{1540,350},{1540,400 },{1540,450 },{1540,500 },{1540,550 },{1540, 600},{1540, 650},{1540,700 },{1540,750 },{1540,800 },{1540,850 },{1540,900 },{1540,950 } },
	{MenuText,MenuText,MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText, MenuText ,MenuText, MenuText, MenuText, MenuText, MenuText },
	textbarinfo
	);


	TextBar textbar({ L"A����" },
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

		if (_kbhit()) {//����а������£���_kbhit()����������
			auto ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
			if (ch == 27) { return 0; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
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