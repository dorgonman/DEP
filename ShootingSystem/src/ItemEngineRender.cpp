#include "ItemEngine.h"


void ItemEngine::render(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		render(roleSpr);
	}

}

void ItemEngine::render(RoleSprite *roleSpr){
	render(roleSpr->getItems());
}


void ItemEngine::render(vector<Item* > items){
	vector<Item*>::iterator it;
	for(it = items.begin(); it != items.end(); it++){
		Item* item = *it;	
		render(item);
	}
}


void ItemEngine::render(Item *item){
	if(item->isAlive()){
		item->RenderEx();
	}

}