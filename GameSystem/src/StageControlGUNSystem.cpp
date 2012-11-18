#include "StageControl.h"
#include "DepControl.h"
#include "GUNControl.h"
//碰撞偵測的方式：對於每一個敵人，如果敵人還活著的話，我方就去檢查是否擊中敵人，相反的，敵人如果還活著的話，則去檢查敵人是否擊中我方
//撞前要更新位子、撞後要更新血條


void StageControl::collisionDetect(){
	GUNControl::shoot(guns);
	GUNControl::hit(guns, playerSpr);
	GUNControl::update(guns);
//============================================

	vector<RoleSprite*>::iterator it;
	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
		RoleSprite* enemySpr = *it;
		GUNControl::lockon(playerSpr->getGUN(2), enemySpr, 200);
	}

	if (hge->Input_KeyDown(HGEK_A)){
		playerGUNChange();
	}

	if(hge->Input_GetKeyState(HGEK_Z)){	
		GUNControl::trigger(playerGUN);
	}



	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
		RoleSprite* enemySpr = *it;
		if (enemySpr->isAlive()){
			GUNControl::shoot(enemySpr->getGUNS());
			GUNControl::hit(playerSpr->getGUNS(), enemySpr);
			if(enemySpr->getHitPoint()->TestPoint(playerSpr->x, playerSpr->y)){//如果敵方撞到我方
				playerSpr->hpDown(20);
			}
		}
		GUNControl::hit(enemySpr->getGUNS(), playerSpr);	
	}
}



void StageControl::playerGUNChange(){

		shootMode = (shootMode + 1) % 3;
		
		if(shootMode == 0){
			playerGUN = playerSpr->getGUN(0);
		}else if(shootMode == 1){
			playerGUN = playerSpr->getGUN(1);

		}else if(shootMode == 2){
			playerGUN = playerSpr->getGUN(2);
		}

}




