#include "RoleSprite.h"

void RoleSprite::addItem(Item *i){
	items.push_back(i);
}

vector<Item*> RoleSprite::getItems(){
	return items;
}


