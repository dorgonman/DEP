#include "..\include\HitPoint.h"

HitPoint::HitPoint(hgeRect *_rect, float _r){
		rect = _rect;
		r = _r;

}

HitPoint::~HitPoint(){
	if(rect) delete rect;

}

void HitPoint::update(float _x, float _y, float _w, float _h){
			rect->x1 = _x - _w / 2; 
			rect->y1 = _y - _h / 2;
			rect->x2 = _x + _w / 2;
			rect->y2 = _y + _h / 2;
			rect->SetRadius(_x, _y, r);

}


void ExplicitHitPoint::update(float _x, float _y, float _w, float _h){
	HitPoint::update(_x, _y,  _w,  _h);
}