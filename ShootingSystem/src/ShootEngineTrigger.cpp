#include "ShootEngine.h"





void ShootEngine::trigger(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		trigger(roleSpr);
	}

}


void ShootEngine::trigger(RoleSprite* roleSpr){
	if(roleSpr->isAlive()){
		trigger(roleSpr->getGUNS());
	}

}


void ShootEngine::trigger(vector<GUN *> guns){
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;	
		this->trigger(gun);
	}
}


void ShootEngine::trigger(GUN *gun){
	if(gun->isAlive()){
		if(gun->getDSIT() >= gun->getShootingTime()){
			gunTriggerSe->playSoundEffect();
			gun->trigger();
		}
	}
}


