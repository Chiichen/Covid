#include"Map.h"
#include"RenderEngine.h"
#include<iostream>
#include<conio.h>
/*��ĸ�����ּ��ļ���ֵ(keyCode)
����	����	����	����	����	����	����	����
A	65	J	74	S	83	1	49
B	66	K	75	T	84	2	50
C	67	L	76	U	85	3	51
D	68	M	77	V	86	4	52
E	69	N	78	W	87	5	53
F	70	O	79	X	88	6	54
G	71	P	80	Y	89	7	55
H	72	Q	81	Z	90	8	56
I	73	R	82	0	48	9	57
���ּ����ϵļ��ļ���ֵ(keyCode)	���ܼ�����ֵ(keyCode)
����	����	����	����	����	����	����	����
0	96	8	104	F1	112	F7	118
1	97	9	105	F2	113	F8	119
2	98	*	106	F3	114	F9	120
3	99	+	107	F4	115	F10	121
4	100	Enter	108	F5	116	F11	122
5	101	-	109	F6	117	F12	123
6	102	.	110	 	 	 	 
7	103	/	111	 	 	 	 
���Ƽ�����ֵ(keyCode)
����	����	����	����	����	����	����	����
BackSpace	8	Esc	27	Right Arrow	39	-_	189
Tab	9	Spacebar	32	Dw Arrow	40	.>	190
Clear	12	Page Up	33	Insert	45	/?	191
Enter	13	Page Down	34	Delete	46	`~	192
Shift	16	End	35	Num Lock	144	[{	219
Control	17	Home	36	;:	186	/|	220
Alt	18	Left Arrow	37	=+	187	]}	221
Cape Lock	20	Up Arrow	38	,<	188	'"	222
��ý�����ֵ(keyCode)
����	����	����	����	����	����	����	����
������	175	 	 	 	 	 	 
������	174	 	 	 	 	 	 
ֹͣ	179	 	 	 	 	 	 
����	173	 	 	 	 	 	 
�����	172	 	 	 	 	 	 
�ʼ�	180	 	 	 	 	 	 
����	170	 	 	 	 	 	 
�ղ�	171	 	 	 	 	 	 */

int main()
{
	Renderer render(3000,3000);
	Map map;

	HANDLE HOUT = GetStdHandle(STD_OUTPUT_HANDLE);    //��ÿ���̨���
	COORD NewSize = GetLargestConsoleWindowSize(HOUT);//��ÿ���̨������꣬�������ַ���Ϊ��λ
	NewSize.X -= 1;
	NewSize.Y -= 1;    //���Բ��ӣ�����ʱ��ʾ������
	SetConsoleScreenBufferSize(HOUT, NewSize); //���ÿ���̨��������С

	SMALL_RECT DisplayArea = { 0,0,0,0 };
	DisplayArea.Right = NewSize.X;
	DisplayArea.Bottom = NewSize.Y;
	SetConsoleWindowInfo(HOUT, TRUE, &DisplayArea);    //���ÿ���̨��С
	point curcusor;
	curcusor.x = 9;
	curcusor.y = 9;
	//����̨�Ѿ���󻯣����ǳ�ʼλ�ò�����Ļ���Ͻǣ�������´���
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);    //�������
	while (1)
	{

		if (_kbhit()) {//����а������£���_kbhit()����������
			auto ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
			if (ch == 27) { return 0; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
			else if (ch == 119 && curcusor.y > 0 && map.logicmap[curcusor.y - 1][curcusor.x] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y--;
				
			}
			else if (ch == 115 && curcusor.y < map.Ifo.ysize-1 && map.logicmap[curcusor.y + 1][curcusor.x] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y++;
			}
			else if (ch == 97 && curcusor.x > 0 && map.logicmap[curcusor.y][curcusor.x - 1] == 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x--;
			}
			else if (ch == 100 && curcusor.x < map.Ifo.xsize - 1&&map.logicmap[curcusor.y][curcusor.x + 1]==1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x++;
			}
		}
		map.SetColor(curcusor, Cube1);
		render.RenderMap(map.Ifo, L"    ", 4, map.rgbdata);

	}
	return 0;

}