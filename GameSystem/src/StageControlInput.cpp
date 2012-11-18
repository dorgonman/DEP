#include "StageControl.h"




void StageControl::processBattleInput(){
	if (g_hge->Input_GetKeyState(HGEK_UP)){ 
		playerSpr->runUp();
	}
	if (g_hge->Input_GetKeyState(HGEK_DOWN)){ 
		playerSpr->runDown();
	}
	if (g_hge->Input_GetKeyState(HGEK_LEFT)){
		playerSpr->runLeft();	
	}

	if (g_hge->Input_GetKeyState(HGEK_RIGHT)){
		playerSpr->runRight();	
	}
	if(playerSpr->getDirection() == RoleSprite::UP){
		playerSpr->SetTextureRect(90, 0, 45, 45);
	}
	if(playerSpr->getDirection() == RoleSprite::DOWN){
		playerSpr->SetTextureRect(0, 0, 45, 45);
	}
	if(playerSpr->getDirection() == RoleSprite::LEFT){
		playerSpr->SetTextureRect(45, 0, 45, 45);
	}
	if(playerSpr->getDirection() == RoleSprite::RIGHT){
		playerSpr->SetTextureRect(0, 0, 45, 45);
	}

	if(g_hge->Input_GetKeyState(HGEK_Z)){
		playerSe->trace(playerSpr->getGUN(0), enemySprs, 0);
		playerSe->trigger(playerGUN);
	}else{
		playerSe->trace(playerSpr->getGUN(2), enemySprs);
	}


	vector<RoleSprite*>::iterator it;
	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
		RoleSprite* enemySpr = *it;	
		if(enemySpr->getDirection() == RoleSprite::UP){	}
		if(enemySpr->getDirection() == RoleSprite::DOWN){enemySpr->SetTextureRect(0, 0, 45, 45);}
		if(enemySpr->getDirection() == RoleSprite::LEFT){enemySpr->SetTextureRect(0, 0, 45, 45);}
		if(enemySpr->getDirection() == RoleSprite::RIGHT){enemySpr->SetTextureRect(0, 0, 45, 45);}
	}

}