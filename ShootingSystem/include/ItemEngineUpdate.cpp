#include "ItemEngine.h"


void ItemEngine::update(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		update(roleSpr);
	}

}


void ItemEngine::update(RoleSprite *roleSpr){
	update(roleSpr->getItems());
}

void ItemEngine::update(std::vector<Item*> items){
	vector<Item*>::iterator it;
	for(it = items.begin(); it != items.end(); it++ ){
		 Item* item = *it;
		 update(item);
	}
}

void ItemEngine::update(Item *item){
	if(item->isAlive()){
	 item->update();
	}
}