#pragma once
#include"RenderEngine.h"
#include<random>
#include<Windows.h>
#include<queue>
using namespace std;
struct point {
	int x = 0;
	int y = 0;
};
int random_unint(unsigned int min, unsigned int max)
{
	std::random_device rd;
	static std::default_random_engine e(rd());
	std::uniform_int_distribution<int> u(min, max);
	return u(e);
}

double random_unint(double min, double max)
{
	std::random_device rd;
	static std::default_random_engine e(rd());
	std::uniform_real_distribution<double> u(min, max);
	return u(e);
}

template<int maxx,int maxy>
void bfsmap(int(&a)[maxx][maxy], double prameter)
{
	const int b[4] = { 0,0,maxx - 1,maxx - 1 };
	const int c[4] = { 0,maxy - 1,0,maxy - 1 };
	const int xx[5] = { 0,0,0,1,-1 };
	const int yy[5] = { 0,1,-1,0,0 };
	queue<point> que;
	for (int i = 0; i < 4; i++)
	{
		point p;
		p.x = b[i], p.y = c[i];
		que.push(p);
		bool flag = true;
		while (!que.empty())
		{
			point cur = que.front();
			que.pop();
			for (int i = 0; i < 5; i++)
			{
				cur.x += xx[i]; cur.y += yy[i];
				if (cur.x >= 0 && cur.x < maxx && cur.y >= 0 && cur.y < maxy && a[cur.x][cur.y] == 0 && (random_unint((double)0, (double)1) <= prameter || flag))
				{
					flag = false;
					a[cur.x][cur.y] = 1;
					que.push(cur);
				}
			}
		}
		
	}
	return;
}
class Map
{
public:
	Map();
	~Map();
	int logicmap[20][20] = { 0 };
	RGBData rgbdata[20][20] = { 0 };
private:

};


