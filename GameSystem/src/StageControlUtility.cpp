#include "StageControl.h"


void StageControl::renderGameInformation(){

	static DEPSprite* p = new DEPSprite(g_rm->GetTexture(".\\Picture\\infor4.jpg"), 0, 0, 200, 600);

	p->Render(600, 0);
	radarView->RenderEx(0, 0, 0, 0.1f, 0.1f);


}

void  StageControl::clearEnemy(){
	//把活著的怪物全部清掉
	vector<RoleSprite*>::iterator it;
	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
			RoleSprite* enemySpr = *it;
			enemySpr->setAlive(false);
	}
}
