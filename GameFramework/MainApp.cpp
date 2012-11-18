

#include "DepControl.h"



void sceneInit();

void System_SetState();//設定系統各種參數




DepControl* dep;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	dep = DepControl::getInstance();//初始化
	dep->setWindowMode(true);
	//dep->setTitle("幽明幻境");
	//dep->setScreen(100, 100);
	dep->setCameraViewSize(600, 600);
	dep->setFPS(60);
	dep->setMapSize(2000, 1200);

	if(dep->initialize()){
			
		dep->addGame(new GameControl());
		dep->selectGame(0);
		dep->systemStart();
	}

	dep->systemShutDown();
	return 0;
}



bool exitFunc(){

		
	return true;

}

