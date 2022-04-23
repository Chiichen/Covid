#pragma once
#include"RenderEngine.h"
#include<random>
#include<Windows.h>
#include<queue>
using namespace std;

double random_unint(double min, double max);

int random_unint(unsigned int min, unsigned int max);

template<int maxx, int maxy>
void bfsmap(int(&a)[maxx][maxy], double prameter);

struct point {
	int x = 0;
	int y = 0;
};

class Map
{
public:
	Map();
	~Map();
	int logicmap[20][20] = { 0 };
	RGBData rgbdata[20][20];
	MapInfo Ifo;
	void SetColor(point p, RGBData data);
private:


};


