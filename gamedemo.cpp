#include"Map.h"
#include"RenderEngine.h"
#include<iostream>
#include<conio.h>
/*字母和数字键的键码值(keyCode)
按键	键码	按键	键码	按键	键码	按键	键码
A	65	J	74	S	83	1	49
B	66	K	75	T	84	2	50
C	67	L	76	U	85	3	51
D	68	M	77	V	86	4	52
E	69	N	78	W	87	5	53
F	70	O	79	X	88	6	54
G	71	P	80	Y	89	7	55
H	72	Q	81	Z	90	8	56
I	73	R	82	0	48	9	57
数字键盘上的键的键码值(keyCode)	功能键键码值(keyCode)
按键	键码	按键	键码	按键	键码	按键	键码
0	96	8	104	F1	112	F7	118
1	97	9	105	F2	113	F8	119
2	98	*	106	F3	114	F9	120
3	99	+	107	F4	115	F10	121
4	100	Enter	108	F5	116	F11	122
5	101	-	109	F6	117	F12	123
6	102	.	110	 	 	 	 
7	103	/	111	 	 	 	 
控制键键码值(keyCode)
按键	键码	按键	键码	按键	键码	按键	键码
BackSpace	8	Esc	27	Right Arrow	39	-_	189
Tab	9	Spacebar	32	Dw Arrow	40	.>	190
Clear	12	Page Up	33	Insert	45	/?	191
Enter	13	Page Down	34	Delete	46	`~	192
Shift	16	End	35	Num Lock	144	[{	219
Control	17	Home	36	;:	186	/|	220
Alt	18	Left Arrow	37	=+	187	]}	221
Cape Lock	20	Up Arrow	38	,<	188	'"	222
多媒体键码值(keyCode)
按键	键码	按键	键码	按键	键码	按键	键码
音量加	175	 	 	 	 	 	 
音量减	174	 	 	 	 	 	 
停止	179	 	 	 	 	 	 
静音	173	 	 	 	 	 	 
浏览器	172	 	 	 	 	 	 
邮件	180	 	 	 	 	 	 
搜索	170	 	 	 	 	 	 
收藏	171	 	 	 	 	 	 */

int main()
{
	Renderer render(3000,3000);
	Map map;
	while (1)
	{
		point curcusor;
		curcusor.x = 9;
		curcusor.y = 9;
		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			auto ch = _getch();//使用_getch()函数获取按下的键值
			cout << ch;
			if (ch == 27) { return 0; }//当按下ESC时循环，ESC键的键值时27.
			else if (ch == 87 && curcusor.y > 0)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y--;
			}
			else if (ch == 87 && curcusor.y < map.Ifo.ysize-1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.y++;
			}
			else if (ch == 65 && curcusor.x > 0)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x--;
			}
			else if (ch == 68 && curcusor.x < map.Ifo.xsize - 1)
			{
				map.SetColor(curcusor, DefaultCube);
				curcusor.x++;
			}

		}
		map.SetColor(curcusor, Cube1);
		render.RenderMap(map.Ifo, L"   ", 4, map.rgbdata);

	}
	return 0;

}