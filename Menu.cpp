#include"Menu.h"
Menu::Menu()
	:renderer(3000, 3000), 
	menutext({ L"➢开始游戏", L"成就", L"技能" }), 
	textsize({ 5, 2, 2 }),
	points({ {962,400},{962,500},{962,600} }),
	rgbdatas({ MenuText ,MenuText ,MenuText }),
	defaulttext1({ L"开始游戏", L"成就", L"技能" }),
	defaulttext2({ L"➢开始游戏", L"➢成就", L"➢技能" }),
	defaulttextsize({4,2,2})
{
	
}


Menu::~Menu()
{
}

int Menu::show()
{
	int curpos = 0;
	int state = 1;
	while (1)
	{
		renderer.RenderText(menuinfo, points, menutext, textsize, rgbdatas,1);
		renderer.Render(appinfo);
		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			auto ch = _getch();//使用_getch()函数获取按下的键值
			if (ch == 13)
			{
				return state;
			}
			else if (ch == 119 && curpos > 0)
			{
				menutext = defaulttext1;
				textsize = defaulttextsize;
				curpos--;
				state--;
				menutext[curpos] = defaulttext2[curpos];
				textsize[curpos]++;
			}
			else if (ch == 115 && curpos < textsize.size() - 1)
			{
				menutext = defaulttext1;
				textsize = defaulttextsize;
				curpos++;
				state++;
				menutext[curpos] = defaulttext2[curpos];
				textsize[curpos]++;
			}
		}
	}

	
	return state;
}
