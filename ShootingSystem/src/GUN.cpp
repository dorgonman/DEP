#include "GUN.h"
#include "ShootEngine.h"


GUN::~GUN(){
	int i;
	for(i = 0; i < (int)bulletSprs.size(); i++){
		delete  bulletSprs[i];
	}
}


GUN::GUN(HTEXTURE tex, float x, float y, float w, float h) : DEPSprite(tex, x, y, w, h){
		hge->Random_Seed();
	setAlive(false);
}



void GUN::setAlive(bool _alive){

	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bulletSpr= *it;
		bulletSpr->setAlive(false);
		bulletSpr->setColor(0xFFFFFFFF);
	}
	sit = 1;
	dsit = 0;
	shootTheta = 0;
	theta = 0;
	alive = _alive;
	bullet = 0;
	pattern = 0;	
	this->setBulletHitRadius(2);
	x = 0;
	y = 0;
	destX = x;
	destY = y;
}




void GUN::trigger(){
	this->dsit = 0;
}

void GUN::update(){
	DEPSprite::update();
	dsit += hge->Timer_GetDelta();
	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		if(bullet->isAlive()){
			bullet->update();
			bullet->run();
		}
	}

	shootTheta = ShootEngine::getTheta(x, y, destX, destY);

}


void GUN::RenderEx(){
	DEPSprite::RenderEx();
	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		if(bullet->isAlive()){
			bullet->RenderEx();
		}
	}

}


