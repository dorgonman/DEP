#include    "Bullet.h"
#include    "math.h"
#include "RoleSprite.h"

void Bullet::initialize(){
	SetHotSpot();
	ai->setMapRange(0, 0, 800, 600);
	setVelocity(5, 5);
	t =2;
	setAlive(false);
	hge->Random_Seed();

}

void Bullet::run(){//是否超過飛行時間
	if(dt >= t){
		setAlive(false);
	}

	dt +=  hge->Timer_GetDelta();
	
}


void Bullet::setAlive(bool _alive){
	px = 0;
	py = 0;
	rotation = 0;
	dt = 0;
	
	theta = hge->Random_Float(0, 360);
	lethality = 20;

	px = 0; py = 0;
	hitPoint->setHitRadius(5);
	Direct[0] = true;
	Direct[1] = false;
	Direct[2] = false;
	Direct[3] = false;
	alive = _alive;
}


void Bullet::hit(RoleSprite *spr){
	spr->hpDown(lethality);
	alive = false;
}


void WaveBullet::run(){
	

}