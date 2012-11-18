#include "ShootEngine.h"




void ShootEngine::render(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		render(roleSpr);
	}

}


void ShootEngine::render(RoleSprite *roleSpr){
	if(roleSpr->isAlive()){
		render(roleSpr->getGUNS());
	}
}

void ShootEngine::render(std::vector<GUN*> guns){
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;	
		render(gun);
	}
}

void ShootEngine::render(GUN *gun){
	gun->RenderEx();
}



