#include "hge.h"


#ifndef DEP_BAR
#define DEP_BAR


class BAR{
public:
	BAR(float _w, float _h, int _color);
	~BAR();
	void Render(float _x, float _y);
	void setLength(float _multiplier); //以目前的長度乘以一個數字來做長度控制
private:
	hgeQuad quad;
	float x, y; //bar左上角的第一點座標
	float high, width, length;
	float multiplier;
	HGE* hge;
};

#endif