#include    "RoleSprite.h"


void PlayerSprite::initialize(){
	dt = 0;
	ishit = false;
	ht = 1.5f;
	hitPoint = new ExplicitHitPoint(this->GetBoundingBox(), 5);
}





void PlayerSprite::checkEffectTime(){

		if(ishit){
			dt += hge->Timer_GetDelta();
			if(dt > ht){
				ishit = false;
				setAphabate(0xFF);
				dt = 0;
			}
		}

		if(achillean){
			dAT += hge->Timer_GetDelta();
			if(dAT > AT){
				achillean = false;
				dAT = 0;
			}
		}
}




bool PlayerSprite::hpDown(float attack){
	if(!achillean){
		if(!ishit){
				setAphabate(0x55);
				ishit = true;
				return RoleSprite::hpDown(attack);
		}
	}
	return false;
	 
}


