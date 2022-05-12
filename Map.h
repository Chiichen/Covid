#pragma once
#include"RenderEngine.h"
#include<random>
#include<Windows.h>
#include<queue>
#include"Simulator.h"
#include"CubeType.h"
using namespace std;

double random_unint(double min, double max);

int random_unint(unsigned int min, unsigned int max);

template<int maxx, int maxy>
void bfsmap(int(&a)[maxx][maxy], int num);


class Map
{
public:
	Map();
	~Map();
	Area area;
	int logicmap[18][23] = { 0 };
	RGBData rgbdata[18][23];
	RGBData rgbrawdata[18][23];
	//vector<vector<RGBData>> rgbdata;
	//vector<vector<int>> logicmap;
	MapInfo Ifo;
	void SetColor(point p, RGBData data);
	bool GenerallyUpdate();
private:


};


