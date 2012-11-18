#include "ItemEngine.h"



void ItemEngine::runToTarget(std::vector<RoleSprite*> roleSprs){
	vector<RoleSprite*>::iterator it;
	for( it = roleSprs.begin(); it != roleSprs.end(); it++ ){
		RoleSprite* roleSpr = *it;	
		runToTarget(roleSpr);
	}

}

void ItemEngine::runToTarget(RoleSprite *roleSpr){
	runToTarget(roleSpr->getItems());
}




void ItemEngine::runToTarget(vector<Item*> items){
	vector<Item*>::iterator it;
	for(it = items.begin(); it != items.end(); it++ ){
		Item* item = *it;	
		runToTarget(item);
	}

}



void ItemEngine::runToTarget(Item* item){
	if(item->isAlive()){
		if((item->getDT() / item->getMT()) > 0.6f ){
			item->setAphabate(GETA(item->getColor())- 0x05);
		}
		AIEngine* ai = item->getAI();
		ai->runToTarget(item);
	}


}
