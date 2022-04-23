#include"RenderEngine.h"

/*x,y为整个程序的x,y轴长度*/
Renderer::Renderer(int x, int y) 
	:hdc(GetDC(GetConsoleWindow())),MemDC(CreateCompatibleDC(hdc)),hbmp(CreateCompatibleBitmap(hdc,x,y))
{
}

Renderer::~Renderer()
{
	DeleteDC(MemDC);
	DeleteObject(hbmp);
	DeleteDC(hdc);
}

void Renderer::RenderUnit(int x, int y, wstring str, int strsize, RGBData rgbdata)
{
	auto str1 = str.c_str();
	auto tempfont = *Fontlist[rgbdata.fontnum];
	SelectObject(MemDC, tempfont);
	SetBkColor(MemDC, RGB(55,66,33));
	SetTextColor(MemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
	TextOut(MemDC, x, y, str1, strsize);
	DeleteObject(tempfont);
}
