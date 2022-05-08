#include"Menu.h"
Menu::Menu()
	:renderer(3000, 3000), 
	menutext({ L"开始游戏", L"成就", L"技能" }), 
	textsize({ 4, 2, 2 }),
	points({ {500,500},{500,600},{500,700} }),
	rgbdatas({ MenuText ,MenuText ,MenuText })
{
	
}


Menu::~Menu()
{
}

int Menu::show()
{
	int curpos = 0;
	int state = 0;
	while (1)
	{
		renderer.RenderText(menuinfo, points, menutext, textsize, rgbdatas);
		renderer.Render(appinfo);
		if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
			auto ch = _getch();//使用_getch()函数获取按下的键值

		}
	}

	
	return state;
}
