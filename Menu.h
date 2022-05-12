#pragma once
#include"RenderEngine.h"
#include"CubeType.h"
#include<vector>
#include<conio.h>
#include<iostream>
#include <fstream>
using namespace std;
#define KEY_DOWN(vk_code) GetAsyncKeyState(vk_code)&0x8000?1:0


class Menu
{
public:
	Menu(vector<wstring>strlist, vector<int> sizelist, vector<point>points, vector<RGBData>rgbdatas);
	~Menu();
	vector<wstring> menutext;
	vector<int> textsize;
	vector<point> points;
	vector<RGBData> rgbdatas;
	Renderer renderer;
	int show(int,int);
	int show(int a = 10);
private:
	vector<wstring>intro = { L"   +   键————增加医护",
	  L"   -   键————减少医护",
	  L"   H   键————全员核酸",
	  L"   O   键————封城封控",
	  L"   G   键————集中隔离",
	  L"  空格 键————到下一天" };
};

