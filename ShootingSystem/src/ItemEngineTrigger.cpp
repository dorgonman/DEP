#include "ItemEngine.h"



void ItemEngine::trigger(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		trigger(roleSpr);
	}

}


void ItemEngine::trigger(RoleSprite* roleSpr){
	trigger(roleSpr->getItems(), roleSpr->x, roleSpr->y);
}



void ItemEngine::trigger(vector<Item*> items, float x, float y){
		vector<Item*>::iterator it;
		for( it = items.begin(); it != items.end(); it++ ){
			Item* item = *it;	
			trigger(item, x, y);
		}
}

void ItemEngine::trigger(Item *item, float x, float y){
	if(!item->isAlive()){
		item->setAlive(true);
		item->setPosition(x, y);
		AIEngine* ai = item->getAI();
		ai->randomSearch(&item->targetX, &item->targetY);
	}
}


