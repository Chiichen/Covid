#pragma once
//È«ÆÁ´óÐ¡ 1925¡Á1000
struct MapInfo
{
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int xsize = 0;
    int ysize = 0;
};


struct point {
    int x = 0;
    int y = 0;
};

struct RGBData
{
    int R = 0;
    int G = 0;
    int B = 0;
    int fontnum = 0;
    int fontsize = 0;
    RGBData(int a, int b, int c, int d) :R(a), G(b), B(c), fontnum(d) { if (d == 0) { fontsize = 40; } else if (d == 1) { fontsize = 50; } }
    RGBData(int a, int b, int c, int d, int e) :R(a), G(b), B(c), fontnum(d), fontsize(e) {}
    RGBData(int a) :R(a), G(a), B(a), fontnum(a) { fontsize = 40; }
    RGBData(){}
};
static const RGBData Cube1(0,245,255,1);
static const RGBData DefaultCube(22, 113, 37, 0);
static const RGBData DarkCube(0, 0, 0, 0);
static const RGBData MenuText(30, 255, 138, 2,50);



static const MapInfo mapinfo = { 0,0,1500,1000,23,18 };
static const MapInfo textinfo = { 1525,0,425,1000,0,0 };
static const MapInfo menuinfo= {0,0,2000,2000,0,0};
static const MapInfo appinfo = { 0,0,3000,3000,0,0 };