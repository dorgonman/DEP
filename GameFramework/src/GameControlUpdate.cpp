#include "GameControl.h"
#include "GameView.h"
#include "DepControl.h"
#include "GlobalVariable.h"

void GameControl::gameUpdate(hgeSprite* cameraView){
	setCameraView(cameraView, cameraX, cameraY);
	doGameScript();
	doRenderScript();
}



void GameControl::doLoadingScript(){
	depControl->setGameMode(MAINLOOP);

}

void GameControl::doGameScript(){

	if(depControl->getGameMode() == LOADING){
		doLoadingScript();
		DepControl::getInstance()->setGameMode(MAINLOOP);
	}

	if(depControl->getGameMode()  == MAINLOOP){
		doMainLoopScript(); 
	} 
}


void GameControl::screenUpdate(){
		doScreenScript();
}




void GameControl::doScreenScript(){
	    hgeTTF::Font* fnt = GlobalVariable::getInstance()->getTTF();
		if(fnt){
			fnt->setSize(15);
			fnt->setColor(0xFFFFFFFF);
			fnt->printf(10, 20, L"FPS:%d", g_hge->Timer_GetFPS());
		}

		static bool bwindow = depControl->getWindowMode();
		if(g_hge->Input_KeyDown(HGEK_F4)){
			bwindow = !bwindow;
			depControl->setWindowMode(bwindow);
		}

}












