#include"Map.h"

Map::Map()
{

	bfsmap(logicmap, 0.5);
	RGBData a = { 0 };
	a.R = 255, a.G = 255, a.B = 255, a.fontnum = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			rgbdata[i][j] = a;
		}
	}


}

Map::~Map()
{
}

