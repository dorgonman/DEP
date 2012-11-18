#include "StageControl.h"
#include "DepControl.h"
#include "GUNControl.h"
//�I���������覡�G���C�@�ӼĤH�A�p�G�ĤH�٬��۪��ܡA�ڤ�N�h�ˬd�O�_�����ĤH�A�ۤϪ��A�ĤH�p�G�٬��۪��ܡA�h�h�ˬd�ĤH�O�_�����ڤ�
//���e�n��s��l�B����n��s���


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
			if(enemySpr->getHitPoint()->TestPoint(playerSpr->x, playerSpr->y)){//�p�G�Ĥ輲��ڤ�
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




