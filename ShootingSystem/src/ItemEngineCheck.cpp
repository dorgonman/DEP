#include "ItemEngine.h"

void ItemEngine::check(std::vector<RoleSprite*> sourceSprs, std::vector<RoleSprite*> targetSprs){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
			RoleSprite* targetSpr = *it;
			check(sourceSprs, targetSpr);
	}
}


void ItemEngine::check(std::vector<RoleSprite*> sourceSprs, RoleSprite *targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
	vector<RoleSprite*>::iterator it;
	for( it = sourceSprs.begin(); it != sourceSprs.end(); it++ ){
		RoleSprite* sourceSpr = *it;	
		check(sourceSpr, targetSpr);
	}

}

void ItemEngine::check(RoleSprite *sourceSpr, std::vector<RoleSprite*> targetSprs){
	vector<RoleSprite*>::iterator it;
	for( it = targetSprs.begin(); it != targetSprs.end(); it++ ){
		RoleSprite* targetSpr = *it;	
		check(sourceSpr, targetSpr);
	}
}



void ItemEngine::check(RoleSprite* sourceSpr, RoleSprite* targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
		check(sourceSpr->getItems(), targetSpr);
}

void ItemEngine::check(vector<Item*> items, RoleSprite* targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
		vector<Item*>::iterator it;
		for(it = items.begin(); it != items.end(); it++ ){
				Item* item = *it;
				check(item, targetSpr);
		}
}


void ItemEngine::check(Item *item, RoleSprite *targetSpr){
	if(!targetSpr->isAlive()){
		return;
	}
	if(item->isAlive()){
	
		if(item->GetBoundingBox()->TestPoint(targetSpr->x, targetSpr->y)){
			item->execute(targetSpr);
			if(typeid(*targetSpr) != typeid(EnemySprite)){
				GameVariable::getInstance()->addScore(item->getScore());
			}
			itemGetSe->playSoundEffect();
			hge->System_Log("score:%d", GameVariable::getInstance()->getScore());
		}
	}
}
