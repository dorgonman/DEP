#include "Bullet.h"

void ThetaBullet::setDirection(float _theta){
	this->theta = _theta;
}


void ThetaBullet::run(){
	Bullet::run();
	ai->runTo(this, theta);
}


