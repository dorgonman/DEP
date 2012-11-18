#include "GUN.h"
static float n = 0;
static float dn = 0;

IncreGUN::IncreGUN(HTEXTURE tex, float x, float y, float w, float h) : ThetaGUN(tex, x, y, w ,h){
}


void IncreGUN::update(){
	GUN::update();
	Bullet* bulletSpr1;
	Bullet* bulletSpr2;
	dn += hge->Timer_GetDelta();
	if(dn >= 0.05f){

		dn = 0;
			if(bullet - 1 < 0){
			bulletSpr1 = bulletSprs[0];
			}else{
				bulletSpr1 = bulletSprs[bullet-1];
			}
			bulletSpr2 = bulletSprs[bullet];
			bulletSpr2->setAlive(true);
			bulletSpr2->setPosition(bulletSpr1->x, bulletSpr1->y);//子彈生成點
			bulletSpr2->setDirection(shootTheta);
			bullet = (bullet + 1) % (int)bulletSprs.size();

	}

}