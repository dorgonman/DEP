#include "ShootEngine.h"



void ShootEngine::trace(std::vector<RoleSprite*> sourceSprs, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
			RoleSprite* targetSpr = *it;
			trace(sourceSprs, targetSpr, radius);
	}

}

void ShootEngine::trace(std::vector<RoleSprite*> sourceSprs, RoleSprite *targetSpr, float radius){
	if(!targetSpr->isAlive()){
		return;
	}
	vector<RoleSprite*>::iterator it;
	for( it = sourceSprs.begin(); it != sourceSprs.end(); it++ ){
		RoleSprite* sourceSpr = *it;	
		trace(sourceSpr, targetSpr, radius);
	}

}


void ShootEngine::trace(RoleSprite *sourceSpr, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		trace(sourceSpr, targetSpr, radius);
	}

}

void ShootEngine::trace(RoleSprite* sourceSpr, RoleSprite* targetSpr, float radius){
	if(!targetSpr->isAlive()){
		return;
	}
	trace(sourceSpr->getGUNS(), targetSpr, radius);
}

void ShootEngine::trace(vector<GUN *> guns, RoleSprite *targetSpr, float radius){

	if(!targetSpr->isAlive()){
		return;
	}
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;
		trace(gun, targetSpr, radius);
	}
}



void ShootEngine::trace(GUN* gun, std::vector<RoleSprite*> targetSprs, float radius){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		trace(gun, targetSpr, radius);
	}

}





void ShootEngine::trace(GUN *gun, RoleSprite *targetSpr, float radius){


	if(targetSpr->isAlive()){
		HitPoint* rect = gun->getHitPoint();
		rect->setHitRadius(radius);
		if(rect->Intersect(targetSpr->getHitPoint())){
			ShootEngine::setAllBulletDestination(gun, targetSpr->x, targetSpr->y);
		}
	}else{
		AIEngine* ai = targetSpr->getAI();
		float x, y;
		ai->randomSearch(&x, &y);
		gun->setBulletDestination(x, y);
	}

}
