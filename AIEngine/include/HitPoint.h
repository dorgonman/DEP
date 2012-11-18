#include "hgerect.h"

#ifndef DEP_HITPOINT
#define DEP_HITPOINT


//=============================測試碰撞針測的工具===================================
class HitPoint{
	public:
		HitPoint(hgeRect* _rect, float _r);
		~HitPoint();
		virtual void update(float _x, float _y, float _w, float _h);
		bool Intersect(const HitPoint* hitPoint){
			return rect->Intersect(hitPoint->rect);
		};
		bool TestPoint(float x, float y){
			return rect->TestPoint(x, y);
		};

		void setHitRadius(float _r){r = _r;};
	public:
		hgeRect* rect;
	protected:
		float r;
};

class ExplicitHitPoint :public HitPoint{
	public:
		ExplicitHitPoint(hgeRect* _rect, float _r) : 
			HitPoint(_rect,_r){};	  		  
		void update(float _x, float _y, float _w, float _h);
};

#endif