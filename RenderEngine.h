#pragma once
#include<Windows.h>
#include<cstring>
#include<string>
#include"CubeType.h"
#include<vector>
#include"TextBar.h"
using namespace std;
/*存储每个区域的RGB值和字体编号*/

/*x、y为左上角坐标，width、height为宽度和高度，xsize、ysize为x、y方向上的区域数量，还被用作文字区域的大小结构体*/



class Renderer
{
public:
	Renderer(int xsize, int ysize);//是x,y轴的地图长度
	~Renderer();
    void RenderUnit(HDC DC,int x, int y, wstring str, int strsize, RGBData rgbdata, int mode);
    template<int maxx, int maxy>
    void RenderMap(MapInfo mpi, wstring str, int strsize, RGBData(&rgbdata)[maxy][maxx]);
    void RenderText(MapInfo mpi,vector<point> points, vector<wstring> strlist, vector<int> strsizelist, vector<RGBData> rgbdatalist,int mode);
    void RenderTextbar(TextBar);
    void Render(MapInfo appinfo);

private:
    HFONT font = CreateFont(
        40, // nHeight
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
        50, // nHeight
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
    HFONT font3 = CreateFont(
        50, // nHeight
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
    HFONT* Fontlist[3] = { &font, &font2, &font3 };
    HDC hdc;
    HDC MemDC;
    HDC MemMapDC;
    HDC MemTextDC;
    HDC CoverMemDC;
    HBITMAP Memhbmp;
    HBITMAP hbmp;
};
/*randermap函数传入mapinfo地图信息，表示地图方格的str(暂定为空格)，str的长度
以及存储rgb信息的二维数组，rgb结构体的信息详见结构体定义部分*/

template<int maxx, int maxy>
void Renderer::RenderMap(MapInfo mpi, wstring str, int strsize, RGBData(&rgbdata)[maxy][maxx])
{
    auto temphbmp = CreateCompatibleBitmap(hdc, mpi.width, mpi.height);
    SelectObject(MemMapDC, temphbmp);
    for (int i = 0; i < mpi.xsize; i++)
    {
        for (int j = 0; j < mpi.ysize; j++)
        {
            RenderUnit(MemMapDC,25+mpi.x + i * (mpi.width / mpi.xsize),25+ mpi.y + j * (mpi.height / mpi.ysize), str, strsize, rgbdata[j][i],1);

        }
    }
    BitBlt(MemDC, mpi.x, mpi.y, mpi.width, mpi.height, MemMapDC, mpi.x, mpi.y, SRCCOPY);
    DeleteObject(temphbmp);
}


