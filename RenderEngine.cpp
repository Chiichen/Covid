#include"RenderEngine.h"

/*x,y为整个程序的x,y轴长度*/
Renderer::Renderer(int x, int y) 
	:hdc(GetDC(GetConsoleWindow())),
	MemDC(CreateCompatibleDC(hdc)),
	hbmp(CreateCompatibleBitmap(hdc,x,y)),
	CoverMemDC(CreateCompatibleDC(hdc)),
	MemMapDC(CreateCompatibleDC(hdc)),
	MemTextDC(CreateCompatibleDC(hdc)),
	Memhbmp(CreateCompatibleBitmap(hdc, x, y)),
	MemTextBarDC(CreateCompatibleDC(hdc))
{
	SelectObject(MemDC, Memhbmp);
}

Renderer::~Renderer()
{
	DeleteDC(MemDC);
	DeleteDC(CoverMemDC);
	DeleteObject(hbmp);
	DeleteObject(Memhbmp);
	DeleteDC(hdc);
}

void Renderer::RenderUnit(HDC DC,int x, int y, wstring str, int strsize, RGBData rgbdata,int mode)
{
	auto str1 = str.c_str();
	auto tempfont = *Fontlist[rgbdata.fontnum];
	auto curfontsize = rgbdata.fontsize;
	auto CoverHbmp = CreateCompatibleBitmap(hdc,1920,1080);
	SelectObject(CoverMemDC, tempfont);
	SelectObject(CoverMemDC, CoverHbmp);
	if (mode == 1)
	{
		SetBkColor(CoverMemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
		TextOut(CoverMemDC, 0, 0, str1, strsize);
		BitBlt(DC, x - rgbdata.fontsize / 2, y - rgbdata.fontsize / 2, rgbdata.fontsize , rgbdata.fontsize , CoverMemDC, 0, 0, SRCCOPY);
		DeleteObject(tempfont);
		DeleteObject(CoverHbmp);
	}

	else if (mode == 2)
	{
		SetBkColor(CoverMemDC, TRANSPARENT);
		SetTextColor(CoverMemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
		TextOut(CoverMemDC, 0, 0, str1, strsize);
		BitBlt(DC, x - rgbdata.fontsize * strsize / 2, y - rgbdata.fontsize/ 2, rgbdata.fontsize * strsize, rgbdata.fontsize, CoverMemDC, 0, 0, SRCCOPY);
		DeleteObject(tempfont);
		DeleteObject(CoverHbmp);
	}

	else if (mode == 3)
	{
		SetBkColor(CoverMemDC, TRANSPARENT);
		SetTextColor(CoverMemDC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));
		TextOut(CoverMemDC, 0, 0, str1, strsize);
		BitBlt(DC, x, y, rgbdata.fontsize * strsize, rgbdata.fontsize, CoverMemDC, 0, 0, SRCCOPY);
		DeleteObject(tempfont);
		DeleteObject(CoverHbmp);
	}
	//SetTextColor(DC, RGB(rgbdata.R, rgbdata.G, rgbdata.B));

}

void Renderer::RenderText(MapInfo mpi, vector<point> points, vector<wstring> strlist, vector<int> strsizelist, vector<RGBData> rgbdatalist, int mode)
{
	if (mode == 1)
	{
		auto temphbmp = CreateCompatibleBitmap(hdc, 3000, 3000);
		SelectObject(MemTextBarDC, temphbmp);
		for (size_t i = 0; i < points.size(); i++)
		{
			RenderUnit(MemTextBarDC, points[i].x, points[i].y, strlist[i], strsizelist[i], rgbdatalist[i], 3);
		}
		BitBlt(MemDC, mpi.x, mpi.y, mpi.width, mpi.height, MemTextBarDC, mpi.x, mpi.y, SRCPAINT);
		DeleteObject(temphbmp);
	}
	else if (mode == 2)
	{
		auto temphbmp = CreateCompatibleBitmap(hdc, 3000, 3000);
		SelectObject(MemTextDC, temphbmp);
		for (size_t i = 0; i < points.size(); i++)
		{
			RenderUnit(MemTextDC, points[i].x, points[i].y, strlist[i], strsizelist[i], rgbdatalist[i], 3);
		}
		BitBlt(MemDC, mpi.x, mpi.y, mpi.width, mpi.height, MemTextDC, mpi.x, mpi.y, SRCPAINT);
		DeleteObject(temphbmp);
	}
}

void Renderer::Render(MapInfo apinfo)
{
	 BitBlt(hdc, apinfo.x, apinfo.y, apinfo.width, apinfo.height, MemDC, apinfo.x, apinfo.y, SRCCOPY);
}

void Renderer::RenderTextbar(TextBar textbar,int mode)
{
	RenderText(textbar.Info, textbar.points, textbar.textlist, textbar.textsize, textbar.rgbdatas,mode);

}