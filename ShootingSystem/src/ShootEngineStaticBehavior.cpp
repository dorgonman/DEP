#include "ShootEngine.h"



void ShootEngine::setAllBulletDestination(GUN *gun, float destX, float destY){
	Bullet* bullet;
	int i;
	for(i = 0; i < gun->getBulletAmount(); i++){
		bullet = gun->getBullet(i);
		float theta = ShootEngine::getTheta(bullet->x, bullet->y, destX, destY);
		bullet->setDirection(theta);
	}

}

void ShootEngine::setAllBulletTheta(GUN *gun, float theta){
	int i;
	Bullet* bullet;
	for(i = 0; i < gun->getBulletAmount(); i++){
		bullet = gun->getBullet(i);
		bullet->setDirection(theta);
	}
}


float ShootEngine::getTheta(float originX, float originY, float destX, float destY){
	float distanceX = destX - originX;
	float distanceY = destY - originY;
	if( distanceX == 0.0 ) {distanceX = 1;};
	float theta = (atan(distanceY/distanceX) * 180.0f) / 3.14159f;   //nway
	if( distanceX >= 0 && theta >= 0 ) {theta = theta ;};//1
	if( distanceX <= 0 && theta >= 0 ) {theta =  theta + 180.0f;};//2
	if( distanceX >= 0 && theta <= 0 ) {theta = theta + 360.0f;};//4
	if( distanceX <= 0 && theta <= 0 ) {theta =  theta + 180.0f;};//3
	return theta;
}

