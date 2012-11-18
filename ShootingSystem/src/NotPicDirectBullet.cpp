#include "Bullet.h"


void NotPicDirectBullet::run(){
	
	ThetaBullet::run();
	setPicRotationTheta(RT);
	RT = (float)((int)(RT + dRT) % 360);
}

void BounceNotPicBullet::run(){
	NotPicDirectBullet::run();
	ai->bounce(this);
}