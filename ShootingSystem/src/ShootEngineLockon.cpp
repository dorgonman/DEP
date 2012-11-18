#include "ShootEngine.h"



void ShootEngine::lockon(std::vector<RoleSprite*> sourceSprs, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
			RoleSprite* targetSpr = *it;
			lockon(sourceSprs, targetSpr, radius);
	}

}

void ShootEngine::lockon(std::vector<RoleSprite*> sourceSprs, RoleSprite *targetSpr, float radius){
	if(!targetSpr->isAlive()){
		return;
	}
	vector<RoleSprite*>::iterator it;
	for( it = sourceSprs.begin(); it != sourceSprs.end(); it++ ){
		RoleSprite* sourceSpr = *it;	
		lockon(sourceSpr, targetSpr, radius);
	}

}


void ShootEngine::lockon(RoleSprite *sourceSpr, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		lockon(sourceSpr, targetSpr, radius);
	}

}

void ShootEngine::lockon(RoleSprite* sourceSpr, RoleSprite* targetSpr, float radius){
	if(!targetSpr->isAlive()){
		return;
	}
	lockon(sourceSpr->getGUNS(), targetSpr, radius);
}

void ShootEngine::lockon(vector<GUN *> guns, RoleSprite *targetSpr, float radius){

	if(!targetSpr->isAlive()){
		return;
	}
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;
		lockon(gun, targetSpr, radius);
	}
}



void ShootEngine::lockon(GUN* gun, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		lockon(gun, targetSpr, radius);
	}

}






void ShootEngine::lockon(GUN *gun, RoleSprite *targetSpr, float radius){


	if(targetSpr->isAlive()){
		HitPoint* rect = gun->getHitPoint();
		rect->setHitRadius(radius);
		if(rect->Intersect(targetSpr->getHitPoint())){
			gun->setBulletDestination(targetSpr->x, targetSpr->y);
		}
	}

}
