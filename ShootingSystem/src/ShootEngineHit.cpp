#include "ShootEngine.h"




void ShootEngine::hit(std::vector<RoleSprite*> sourceSprs, std::vector<RoleSprite*> targetSprs){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
			RoleSprite* targetSpr = *it;
			hit(sourceSprs, targetSpr);
	}

}

void ShootEngine::hit(std::vector<RoleSprite*> sourceSprs, RoleSprite *targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
	vector<RoleSprite*>::iterator it;
	for( it = sourceSprs.begin(); it != sourceSprs.end(); it++ ){
		RoleSprite* sourceSpr = *it;	
		hit(sourceSpr, targetSpr);
	}

}


void ShootEngine::hit(RoleSprite *sourceSpr, std::vector<RoleSprite*> targetSprs){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		hit(sourceSpr, targetSpr);
	}

}

void ShootEngine::hit(RoleSprite* sourceSpr, RoleSprite* targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
	hit(sourceSpr->getGUNS(), targetSpr);
}

void ShootEngine::hit(vector<GUN *> guns, RoleSprite *targetSpr){

	if(!targetSpr->isAlive()){
		return;
	}
	vector<GUN*>::iterator it;
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;
		this->hit(gun, targetSpr);
	}
}

void ShootEngine::hit(GUN *gun, RoleSprite *targetSpr){
	Bullet* bullet;
	if(!targetSpr->isAlive()){
		return;
	}
	if(gun->isAlive()){
		int amount = gun->getBulletAmount(); 
		int i;
		for(i = 0; i < amount ;i++){
			bullet = gun->getBullet(i);
			if(bullet->isAlive()){
				if(bullet->getHitPoint()->Intersect(targetSpr->getHitPoint())){
					bullet->hit(targetSpr);
					bulletHitSe->playSoundEffect();
					
					if(targetSpr->getHP() <= 0){
						ItemEngine::trigger(targetSpr);
						roleDieSe->playSoundEffect();
					}
				}			
			}
		}
	}
}


