#include "hge.h"


#ifndef DEP_BAR
#define DEP_BAR


class BAR{
public:
	BAR(float _w, float _h, int _color);
	~BAR();
	void Render(float _x, float _y);
	void setLength(float _multiplier); //�H�ثe�����׭��H�@�ӼƦr�Ӱ����ױ���
private:
	hgeQuad quad;
	float x, y; //bar���W�����Ĥ@�I�y��
	float high, width, length;
	float multiplier;
	HGE* hge;
};

#endif