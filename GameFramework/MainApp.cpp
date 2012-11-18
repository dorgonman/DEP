

#include "DepControl.h"



void sceneInit();

void System_SetState();//�]�w�t�ΦU�ذѼ�




DepControl* dep;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	dep = DepControl::getInstance();//��l��
	dep->setWindowMode(true);
	//dep->setTitle("�թ��۹�");
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

