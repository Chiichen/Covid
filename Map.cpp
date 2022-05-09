#include"Map.h"
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

template<int maxx, int maxy>
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


//
//template<int maxx, int maxy>
//void bfsmap(int(&a)[maxx][maxy], double prameter)
//{
//	const int b[4] = { 0,0,maxx - 1,maxx - 1 };
//	const int c[4] = { 0,maxy - 1,0,maxy - 1 };
//	const int xx[5] = { 0,0,0,1,-1 };
//	const int yy[5] = { 0,1,-1,0,0 };
//	queue<point> que;
//	for (int i = 0; i < 5; i++)
//	{
//		point p;
//		p.x = (maxx-1)/2+xx[i], p.y = (maxy-1)/2+yy[i];
//		que.push(p);
//		bool flag = true;
//		while (!que.empty())
//		{
//			point cur = que.front();
//			que.pop();
//			for (int i = 0; i < 5; i++)
//			{
//				cur.x += xx[i]; cur.y += yy[i];
//				if (cur.x >= 0 && cur.x < maxx && cur.y >= 0 && cur.y < maxy && a[cur.x][cur.y] == 0 && (random_unint((double)0, (double)1) <= prameter || flag))
//				{
//					flag = false;
//					a[cur.x][cur.y] = 1;
//					que.push(cur);
//				}
//			}
//		}
//
//	}
//	return;
//}



void bfsmap(vector<vector<int>>a, double prameter)
{
	int maxx = a.size();
	int maxy = a[0].size();
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


Map::Map()
	:Ifo(mapinfo)
{

	bfsmap(logicmap, 0.8);
	RGBData a = { DefaultCube };
	RGBData b = { DarkCube };
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (logicmap[i][j] == 0)
			{
				area.area_arr[i * 23 + j]->Existence = 0;
				area.area_arr[i * 23 + j]->setInfectious_num(0);
				rgbdata[i][j] = b;
			}
			else {
				area.area_arr[i * 23 + j]->Existence = 1;
				rgbdata[i][j] = a;
			}

		}
	}


}

void Map::SetColor(point p, RGBData data)
{
	rgbdata[p.y][p.x] = data;
}

Map::~Map()
{
}

