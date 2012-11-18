#include "Bullet.h"
#include    "RoleSprite.h"

void PicDirectBullet::run(){
	ThetaBullet::run();
	setPicRotationTheta(theta);
}


void PenetratePicDirectBullet::hit(RoleSprite* spr){
	spr->hpDown(lethality);
}




