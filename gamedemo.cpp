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
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
//���ع��


	Renderer render(3000, 3000);
	Map map;
	Menu menu;
	TextBar textbar;


	point curcusor;
	curcusor.x = 9;
	curcusor.y = 9;

	int state = menu.show();

	while (state == 1)
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
		}
		
		map.area.area_arr[curcusor.x*curcusor.y]->getKnown_Infectious();
		vector<wstring>str;
		map.SetColor(curcusor, Cube1);
		render.RenderMap(mapinfo, L"    ", 4, map.rgbdata);
		render.RenderTextbar(textbar);
		render.Render(appinfo);


	}
	return 0;

}