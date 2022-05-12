#include"TextBar.h"
TextBar::TextBar(vector<wstring>a, vector<int>b, vector<point>c, vector<RGBData>d,MapInfo info)
	:textlist(a),
	textsize(b),
	points(c),
	rgbdatas(d),
	Info(info)
{

}

TextBar::~TextBar()
{

}

void TextBar::SetTextbar(vector<wstring>a, vector<int>b, vector<point>c, vector<RGBData>d, MapInfo info)
{
	textlist = a;
	textsize = b;
	points = c;
	rgbdatas = d;
	Info = info;
}


//¨U¨X¨Y¨Z¨[¨\¨]¨^¨_¨`¨a¨T¨g¨d