#pragma once
//È«ÆÁ´óÐ¡ 1925¡Á1000
#include<Windows.h>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
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
static const RGBData InfoText{ 245,245,220,3,25 };
static const RGBData EventText{ 255,48,48,3,25 };
static const RGBData InfectedCube1{ 253,214,99,0,40 };
static const RGBData InfectedCube2{ 249,171,0,0,40 };
static const RGBData InfectedCube3{ 232,112,8,0,40 };
static const RGBData InfectedCube4{ 197,34,30,0,40 };
static const RGBData InfectedCube5{ 165,13,13,0,40 };
static const RGBData DateText(245, 245, 220, 4, 30);
static const RGBData IntroText{238,233,233,5,80 };

static const MapInfo mapinfo = { 0,0,1500,1000,23,18 };
static const MapInfo textinfo = { 1560,50,250,350,0,0 };
static const MapInfo textinfo2 = { 1560,450,250,500,0,0 };
static const MapInfo textbarinfo = { 1550,0,1000,1080,0,0 };
static const MapInfo menuinfo= {0,0,2000,2000,0,0};
static const MapInfo appinfo = { 0,0,3000,3000,0,0 };


static const vector<point> EventPoints = { {1575,50},{1575, 100} ,{1575,150 } ,{1575, 200} ,{1575, 250} ,{1575, 300} ,{1575, 350} };
static const vector<point> InfoPoints = { {1575, 450},{1575, 500},{1575, 550},{1575, 600},{1575, 650},{1575, 700},{1575, 750},{1575, 800},{1575, 850},{1575, 900} };

static const vector<RGBData>InfoRGB = { InfoText,InfoText, InfoText, InfoText, InfoText, InfoText, InfoText, InfoText, InfoText ,InfoText};
static const vector<RGBData> EventRGB = { DateText,EventText, EventText, EventText, EventText, EventText,EventText};


static vector<int> getnum(vector<wstring>strlist)
{
    vector<int>ans;
    for (auto &e : strlist)
    {
        ans.push_back(e.size());
    }
    return ans;
}