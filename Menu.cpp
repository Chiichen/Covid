#include"Menu.h"
Menu::Menu()
	:renderer(3000, 3000), 
	menutext({ L"��ʼ��Ϸ", L"�ɾ�", L"����" }), 
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
		if (_kbhit()) {//����а������£���_kbhit()����������
			auto ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ

		}
	}

	
	return state;
}
