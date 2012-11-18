#include "ShootEngine.h"




void ShootEngine::update(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		update(roleSpr);
	}

}


void ShootEngine::update(RoleSprite *roleSpr){
	update(roleSpr->getGUNS());
}

void ShootEngine::update(std::vector<GUN*> guns){
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;	
		update(gun);
	}
}

void ShootEngine::update(GUN *gun){
	gun->update();
}



