

#include "DepControl.h"
#include "Stage.h"
//#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")//�h�@��CONSOLE
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

void sceneInit();

void System_SetState();//�]�w�t�ΦU�ذѼ�




DepControl* dep;

//���ج[�S����device restore��solve size stretch�����D
//���C���ج[�w�쬰�p�C���}�o
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	/*SetConsoleTitleW( L"testMyConsole "); 
	HANDLE   hwnd   =   FindWindowW(NULL, L"testMyConsole "); 
	ShowWindow((HWND)hwnd,SW_HIDE); */
	dep = DepControl::getInstance();//��l��
	dep->setWindowMode(true);
	dep->setTitle("�թ��۹�");
	dep->setScreen(800, 600);
	dep->setCameraViewSize(600, 600);
	dep->setFPS(30);
	dep->setMapSize(1200, 1200);
	if(dep->initialize()){
		dep->addGame(new StageTitle());
		dep->addGame(new Stage1());
	    dep->addGame(new StageExtra());
		dep->selectGame(0);
		dep->systemStart();
	}

	dep->systemShutDown();
	

	return 0;
}



bool exitFunc(){

		
	return true;

}

