#include"RenderEngine.h"

/*x,y为整个程序的x,y轴长度*/
Renderer::Renderer(int x, int y) 
	:hdc(GetDC(GetConsoleWindow())),MemDC(CreateCompatibleDC(hdc)),hbmp(CreateCompatibleBitmap(hdc,x,y)),CoverMemDC(CreateCompatibleDC(hdc))
{
}

Renderer::~Renderer()
{
	DeleteDC(MemDC);
	DeleteDC(CoverMemDC);
	DeleteObject(hbmp);
	DeleteDC(hdc);
}

void Renderer::RenderUnit(int x, int y, wstring str, int strsize, RGBData rgbdata)
{
	
	auto str1 = str.c_str();
	auto tempfont = *Fontlist[rgbdata.fontnum];
	auto curfontsize = rgbdata.fontsize;
	auto CoverHbmp = CreateCompatibleBitmap(hdc,300,300);
	SelectObject(CoverMemDC, tempfont);
	SelectObject(CoverMemDC, CoverHbmp);
	SetBkColor(CoverMemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
	//SetTextColor(CoverMemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
	//SetTextColor(MemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
	TextOut(CoverMemDC, 0, 0, str1, strsize);
	BitBlt(MemDC, x - rgbdata.fontsize/2, y-rgbdata.fontsize/2,rgbdata.fontsize,rgbdata.fontsize, CoverMemDC,0,0,SRCCOPY);
	DeleteObject(tempfont);
	DeleteObject(CoverHbmp);
}

