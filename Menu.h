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
	vector<wstring>intro = { L"   +   ��������������ҽ��",
	  L"   -   ��������������ҽ��",
	  L"   H   ����������ȫԱ����",
	  L"   O   ������������Ƿ��",
	  L"   G   �������������и���",
	  L"  �ո� ��������������һ��" };
};

