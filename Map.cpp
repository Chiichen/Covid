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
void bfsmap(int(&a)[maxx][maxy], int num)
{
	//const int b[4] = { 0,0,maxx - 1,maxx - 1 };
	//const int c[4] = { 0,maxy - 1,0,maxy - 1 };
	const int xx[5] = { 0,0,0,1,-1 };
	const int yy[5] = { 0,1,-1,0,0 };
	queue<point> que;
	int count=0;

		point p;
		p.x = 9, p.y = 11;
		que.push(p);
		bool flag = true;
		while (!que.empty())
		{
			point curcur = que.front();
			que.pop();
			for (int i = 0; i < 5; i++)
			{
				point cur = curcur;
				cur.x += xx[i]; cur.y += yy[i];
				if (cur.x >= 0 && cur.x < maxx && cur.y >= 0 && cur.y < maxy && a[cur.x][cur.y] == 0 &&random_unint((unsigned int)0,(unsigned int)10)<5 && count <= num || flag)
				{
					flag = false;
					a[cur.x][cur.y] = 1;
					que.push(cur);
					count++;
				}
				else if (count < num/3 &&que.empty())
				{
					que.push(curcur);
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
//
//
//
//void bfsmap(vector<vector<int>>a, double prameter)
//{
//	int maxx = a.size();
//	int maxy = a[0].size();
//	const int b[4] = { 0,0,maxx - 1,maxx - 1 };
//	const int c[4] = { 0,maxy - 1,0,maxy - 1 };
//	const int xx[5] = { 0,0,0,1,-1 };
//	const int yy[5] = { 0,1,-1,0,0 };
//	queue<point> que;
//	for (int i = 0; i < 4; i++)
//	{
//		point p;
//		p.x = b[i], p.y = c[i];
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


Map::Map()
	:Ifo(mapinfo)
{

	bfsmap(logicmap, 150);
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
				rgbrawdata[i][j] = b;
			}
			else {
				area.area_arr[i * 23 + j]->Existence = 1;
				rgbdata[i][j] = DefaultCube;
				rgbrawdata[i][j] = DefaultCube;
			}

		}
	}

	area.area_arr[237]->setActual_Infectious(10);
}

void Map::SetColor(point p, RGBData data)
{
	rgbdata[p.y][p.x] = data;
}

Map::~Map()
{
}

bool Map::GenerallyUpdate()
{
	int cnt = 0;
	area.GenerallyUpdate();
	if (area.date % 7 == 0)
	{
		int a = random_unint((unsigned int)0, (unsigned int)23 * 18);
		area.area_arr[a]->setActual_Infectious(10);
		if (logicmap[a / 23][a % 23] == 1)
		{
			area.addevent(L"(" + to_wstring(area.area_arr[a]->getLoccalCoord().x+1) + L"," + to_wstring(area.area_arr[a]->getLoccalCoord().y+1) + L")有不明传染性疾病");
		}
		
	}

		for (int i = 0; i < I * J; i++)
		{
			if (logicmap[i / 23][i % 23] == 1)
			{
				if (area.area_arr[i]->getActaul_Infectious() == 0)
				{
					rgbdata[i / 23][i % 23] = DefaultCube;
					rgbrawdata[i / 23][i % 23] = DefaultCube;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() < 5)
				{

					rgbdata[i / 23][i % 23] = InfectedCube1;
					rgbrawdata[i / 23][i % 23] = InfectedCube1;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() < 10)
				{
					rgbdata[i / 23][i % 23] = InfectedCube2;
					rgbrawdata[i / 23][i % 23] = InfectedCube2;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() < 30)
				{
					rgbdata[i / 23][i % 23] = InfectedCube3;
					rgbrawdata[i / 23][i % 23] = InfectedCube3;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() < 40)
				{
					rgbdata[i / 23][i % 23] = InfectedCube4;
					rgbrawdata[i / 23][i % 23] = InfectedCube4;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() < 50)
				{
					rgbdata[i / 23][i % 23] = InfectedCube5;
					rgbrawdata[i / 23][i % 23] = InfectedCube5;
				}
				else if (area.area_arr[i]->getActaul_Infectious() * 100 / area.area_arr[i]->getPopulation() >= 50)
				{
					cnt++;
				}

			}

		}
			if(cnt>=5)		return false;

		return true;
	}


