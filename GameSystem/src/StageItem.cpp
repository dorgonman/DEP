#include "StageItem.h"
#include "RoleSprite.h"

void SmallHPItem::execute(RoleSprite *role){
	Item::execute(role);
	role->addHP(30);
}


void BigHPItem::execute(RoleSprite *role){
	 Item::execute(role);
	 role->addHP(120);
}


void PanaceaItem::execute(RoleSprite *role){
	 Item::execute(role);
	 role->addHP(120);
}