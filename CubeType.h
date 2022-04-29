#pragma once
#include"RenderEngine.h"
struct RGBData
{
    int R = 0;
    int G = 0;
    int B = 0;
    int fontnum = 0;
    int fontsize = 0;
    RGBData(int a, int b, int c, int d) :R(a), G(b), B(c), fontnum(d) { if (d == 0) { fontsize = 40; } else if (d == 1) { fontsize = 50; } }
    RGBData(int a) :R(a), G(a), B(a), fontnum(a) { fontsize = 40; }
    RGBData(){}
};
static RGBData Cube1(0,245,255,1);
static RGBData DefaultCube(22, 113, 37, 0);
static RGBData DarkCube(0, 0, 0, 0);

