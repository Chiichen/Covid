#pragma once
#include<Windows.h>
#include<cstring>
#include<string>
using namespace std;
/*�洢ÿ�������RGBֵ��������*/
struct RGBData
{
    int R=0;
    int G=0;
    int B=0;
    int fontnum=0;
};
/*x��yΪ���Ͻ����꣬width��heightΪ��Ⱥ͸߶ȣ�xsize��ysizeΪx��y�����ϵ���������*/
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
	Renderer(int xsize, int ysize);
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
        TRUE, // bItalic
        FALSE, // bUnderline
        0, // cStrikeOut
        ANSI_CHARSET, // nCharSet
        OUT_DEFAULT_PRECIS, // nOutPrecision
        CLIP_DEFAULT_PRECIS, // nClipPrecision
        DEFAULT_QUALITY, // nQuality
        DEFAULT_PITCH | FF_SWISS,
        L"(��ͨ�ı�)"// nPitchAndFamily Arial
    );
    HFONT* Fontlist[1] = { &font };
    HDC hdc;
    HDC MemDC;
    HBITMAP hbmp;
};
