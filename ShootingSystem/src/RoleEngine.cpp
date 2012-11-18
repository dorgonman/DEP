#include "RoleEngine.h"



void RoleEngine::update(vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		update(roleSpr);
	}

}

void RoleEngine::update(RoleSprite *roleSpr){
	if(roleSpr->isAlive()){
		roleSpr->update();
	}
	ShootEngine::update(roleSpr->getGUNS());
	ItemEngine::update(roleSpr->getItems());

}

void RoleEngine::render(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		render(roleSpr);
	}

}

void RoleEngine::render(RoleSprite *roleSpr){
	if(roleSpr->isAlive()){
		roleSpr->RenderEx();
	}
	ShootEngine::render(roleSpr->getGUNS());
	ItemEngine::render(roleSpr->getItems());

}