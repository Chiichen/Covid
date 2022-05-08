#pragma once
#include"RenderEngine.h"
#include"CubeType.h"
#include<vector>
#include<conio.h>
using namespace std;
class Menu
{
public:
	Menu();
	~Menu();
	vector<wstring> menutext;
	vector<int> textsize;
	vector<point> points;
	vector<RGBData> rgbdatas;
	Renderer renderer;
	int show();
private:

};

