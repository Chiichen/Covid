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
	auto temphbmp = hbmp;
	SelectObject(MemDC, tempfont);
	SetBkColor(MemDC, TRANSPARENT);
	SetTextColor(MemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
	TextOut(MemDC, x, y, str1, strsize);
	DeleteObject(tempfont);
}

template<int maxx,int maxy>
void Renderer::RenderMap(MapInfo mpi, wstring str, int strsize, RGBData (& rgbdata)[maxy][maxx])
{
	auto temphbmp = CreateCompatibleBitmap(hdc, mpi.width, mpi.height);
	SelectObject(MemDC, temphbmp);
		for (int i = 0; i < mpi.xsize; i++)
		{
			for (int j = 0; j < mpi.ysize; j++)
			{
				RenderUnit(mpi.x + i * (mpi.x / mpi.xsize), mpi.y + j * (mpi.y / mpi.ysize), str, strsize, rgbdata[j][i]);

			}
		}
		BitBlt(hdc, mpi.x, mpi, y, mpi.width, mpi.height, MemDC, mpi.x, mpi.y, SRCCOPY);
		DeleteObject(temphbmp);
}