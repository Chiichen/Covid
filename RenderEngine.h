#pragma once
#include<Windows.h>
#include<cstring>
#include<string>
#include"CubeType.h"
using namespace std;
/*存储每个区域的RGB值和字体编号*/

/*x、y为左上角坐标，width、height为宽度和高度，xsize、ysize为x、y方向上的区域数量*/
struct MapInfo
{
    int x=0;
    int y=0;
    int width=0;
    int height=0;
    int xsize=0;
    int ysize=0;
};

class Renderer
{
public:
	Renderer(int xsize, int ysize);//是x,y轴的地图长度
	~Renderer();
    void RenderUnit(int x, int y, wstring str, int strsize, RGBData rgbdata);
    template<int maxx, int maxy>
    void RenderMap(MapInfo mpi, wstring str, int strsize, RGBData(&rgbdata)[maxy][maxx]);

private:
    HFONT font = CreateFont(
        60, // nHeight
        0, // nWidth
        0, // nEscapement
        0, // nOrientation
        FW_BOLD, // nWeight
        FALSE, // bItalic
        FALSE, // bUnderline
        0, // cStrikeOut
        ANSI_CHARSET, // nCharSet
        OUT_DEFAULT_PRECIS, // nOutPrecision
        CLIP_DEFAULT_PRECIS, // nClipPrecision
        DEFAULT_QUALITY, // nQuality
        DEFAULT_PITCH | FF_SWISS,
        L"Arial"// nPitchAndFamily Arial
    );
    HFONT font2 = CreateFont(
        70, // nHeight
        0, // nWidth
        0, // nEscapement
        0, // nOrientation
        FW_BOLD, // nWeight
        FALSE, // bItalic
        FALSE, // bUnderline
        0, // cStrikeOut
        ANSI_CHARSET, // nCharSet
        OUT_DEFAULT_PRECIS, // nOutPrecision
        CLIP_DEFAULT_PRECIS, // nClipPrecision
        DEFAULT_QUALITY, // nQuality
        DEFAULT_PITCH | FF_SWISS,
        L"Arial"// nPitchAndFamily Arial
    );
    HFONT* Fontlist[2] = { &font, &font2 };
    HDC hdc;
    HDC MemDC;
    HBITMAP hbmp;
};

template<int maxx, int maxy>
void Renderer::RenderMap(MapInfo mpi, wstring str, int strsize, RGBData(&rgbdata)[maxy][maxx])
{
    auto temphbmp = CreateCompatibleBitmap(hdc, mpi.width, mpi.height);
    SelectObject(MemDC, temphbmp);
    for (int i = 0; i < mpi.xsize; i++)
    {
        for (int j = 0; j < mpi.ysize; j++)
        {
            RenderUnit(mpi.x + i * (mpi.width / mpi.xsize), mpi.y + j * (mpi.height / mpi.ysize), str, strsize, rgbdata[j][i]);

        }
    }
    BitBlt(hdc, mpi.x, mpi.y, mpi.width, mpi.height, MemDC, mpi.x, mpi.y, SRCCOPY);
    DeleteObject(temphbmp);
}