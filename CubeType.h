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
    RGBData(int a, int b, int c, int d, int e) :R(a), G(b), B(c), fontnum(d), fontsize(e) {}
    RGBData(){}
};
static const RGBData Cube1(0,245,255,1, 50);
static const RGBData DefaultCube(22, 113, 37, 0, 40);
static const RGBData DarkCube(0, 0, 0, 0,40);
static const RGBData MenuText(30, 255, 138, 2,50);
static const RGBData text1(123, 123, 12, 3, 25);


static const MapInfo mapinfo = { 0,0,1500,1000,23,18 };
static const MapInfo textinfo = { 1560,0,250,400,0,0 };
static const MapInfo textinfo2 = { 1550,450,200,550,0,0 };
static const MapInfo textbarinfo = { 1550,0,1000,1080,0,0 };
static const MapInfo menuinfo= {0,0,2000,2000,0,0};
static const MapInfo appinfo = { 0,0,3000,3000,0,0 };