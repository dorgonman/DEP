

#include "DepControl.h"
#include "Stage.h"
//#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")//多一個CONSOLE
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

void sceneInit();

void System_SetState();//設定系統各種參數




DepControl* dep;

//本框架沒做到device restore跟solve size stretch的問題
//本遊戲框架定位為小遊戲開發
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	/*SetConsoleTitleW( L"testMyConsole "); 
	HANDLE   hwnd   =   FindWindowW(NULL, L"testMyConsole "); 
	ShowWindow((HWND)hwnd,SW_HIDE); */
	dep = DepControl::getInstance();//初始化
	dep->setWindowMode(true);
	dep->setTitle("幽明幻境");
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

