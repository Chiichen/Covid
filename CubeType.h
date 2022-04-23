#pragma once
#include"RenderEngine.h"
struct RGBData
{
    int R = 0;
    int G = 0;
    int B = 0;
    int fontnum = 0;
    RGBData(int a, int b, int c, int d) :R(a), G(b), B(c), fontnum(d) {}
    RGBData(int a):R(a),G(a),B(a),fontnum(a){}
    RGBData(){}
};
static RGBData Cube1(0,245,255,1);
static RGBData DefaultCube(255, 193, 37, 0);

