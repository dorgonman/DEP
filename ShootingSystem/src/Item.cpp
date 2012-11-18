#include "Item.h"
#include "RoleSprite.h"

void Item::initialize(){
		  spr->SetTexture(g_rm->GetTexture(".\\Picture\\job\\PointItem.png"));
		  spr->SetTextureRect(0, 0, 45, 45);
		  SetHotSpot();
		  dt = 0;
		  setAlive(false);
		  score = 100;
		  mt = 15;

}

void Item::update(){

		dt += hge->Timer_GetDelta();
		if(dt > mt){
			 setAlive(false);
		}

}

void Item::execute(RoleSprite *role){
	 setAlive(false);
}


void Item::setAlive(bool _alive){
	DEPSprite::setAlive(_alive);
	dt = 0;
	this->setAphabate(0xFF);

}