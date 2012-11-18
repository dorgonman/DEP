#include "GameView.h"
#include   <string> 
#include "DepControl.h"
GameView::~GameView(){
	delete radarView;
	delete cameraView;
	delete gameControl;

}

GameView::GameView(){
    DepControl* dep = DepControl::getInstance();
		
	radarTarget = g_hge->Target_Create((int)dep->mapWidth, (int)dep->mapHeight, false);
	radarView  = new hgeSprite(g_hge->Target_GetTexture(radarTarget), 0, 0, dep->mapWidth, dep->mapHeight);
	radarView -> SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);

	mapTarget = g_hge->Target_Create((int)dep->mapWidth, (int)dep->mapHeight, false);
	cameraView = new hgeSprite(g_hge->Target_GetTexture(mapTarget), 0, 0, dep->cameraViewX, dep->cameraViewY);
	cameraView->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	cameraView->SetHotSpot(dep->cameraViewX / 2, dep->cameraViewY / 2);
	GlobalVariable* var = GlobalVariable::getInstance();
	var->setStop(false);

	gameControl = new GameControl();
}


void GameView::mapRender(){
	
	g_hge->Gfx_BeginScene(mapTarget);
	g_hge->Gfx_Clear(0);
	gameControl->gameUpdate(cameraView);
	g_hge->Gfx_EndScene();
}

void GameView::radarRender(){
	g_hge->Gfx_BeginScene(radarTarget);
	g_hge->Gfx_Clear(0);
	gameControl->renderPointSpr();
	g_hge->Gfx_EndScene();
}

void GameView::selectGame(int index){
	if((int)games.size() == 0){
		return;
	}

	//�p�G���������d�W�L�}�C�A�h�۰ʪ�^title
	if(index > ((int)games.size() - 1)){
		setGame(games[0]);	
		return;
	}
	  setGame(games[index]);	
}

void GameView::Render(){
	GlobalVariable* var = GlobalVariable::getInstance();

	//�p�G�b�S�Ȱ������p�U�A���b��L�e���W���s����Tø�J
	if(!var->isStop()){
		mapRender();
		radarRender();
	}


	if(!DepControl::getInstance()->getVideoManager()->isPlaying()){
	
		g_hge->Gfx_BeginScene();
		g_hge->Gfx_Clear(0);
		gameControl->setCameraView(cameraView);
		gameControl->setRadarView(radarView);
		gameControl->screenUpdate();
		g_hge->Gfx_EndScene();
	}

}


void GameView::addGame(GameControl *game){
	games.push_back(game);
}


void GameView::resetGame(){
	vector<GameControl*>::iterator it = games.begin();
	for( it = games.begin(); it != games.end(); it++ ){
		GameControl* game = *it;
		game->resetGame();
	}
}





