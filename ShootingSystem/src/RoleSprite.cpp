#include "RoleSprite.h"

void RoleSprite::initialize(){
		  achillean = false;
		  setAlive(false);
}


void RoleSprite::setAlive(bool _alive){
	MHP = 120;
	HP = MHP;
	alive = _alive;

	AT = 5;
	dAT = 0;
	this->setHitRadius(20);
	setAphabate(0xFF);

	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;
		gun->setAlive(false);
		gun->setBulletHitRadius(2);
		gun->setBulletFlyTime(2.0f);
		gun->setBulletVelocity(5, 5);
		gun->setShootingTime(1.0f);
		gun->setBulletSize(0.5f, 0.5f);
		gun->setBulletColor(0xFFFFFFFF);
	}

	vector<Item*>::iterator items_it;
	for( items_it = items.begin(); items_it != items.end(); items_it++ ){
		Item* item = *items_it;
		item->setAlive(false);
	}

}





void RoleSprite::addHP(float _HP){

	HP += _HP;
	if(	HP > MHP){
		HP = MHP;
	}

}




void RoleSprite::update(){
	DEPSprite::update();
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;		
		gun->setPosition(x, y);
	}

	checkEffectTime();
}

void RoleSprite::RenderEx(){
	DEPSprite::RenderEx();
}

bool RoleSprite::hpDown(float attack){
		HP -= attack;
		if(HP <= 0){
			alive = false;
		}

		return true;
}



GUN* RoleSprite::getGUN(int i){
	if((int)guns.size() == 0){
		return NULL;
	}
	if(i > ((int)guns.size() - 1)){
		return guns[0]; 
	}
	return guns[i];
}



//如果設超過陣列則統一處理第一把槍;
void RoleSprite::setGUN(int i, GUN *newGun){
	int n = i;
	if(i > ((int)guns.size() - 1)){
		n = 0;
	}
	guns[n] = newGun;
	guns[n]->setAlive(false);  
	guns[n]->SetHotSpot();	
}



void RoleSprite::addGUN(GUN *newGun){
	newGun->SetHotSpot();
	newGun->setPosition(x, y);
	guns.push_back(newGun);
}



