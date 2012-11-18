#include "DepControl.h"

DepControl* DepControl::instance = NULL;
bool frameFunc();//遊戲主循環
bool exitFunc();

bool frameFunc(){

	DepControl::getInstance()->run();

	if(DepControl::getInstance()->isExit()){
		return exitFunc();
	}
	

	return false;
}



DepControl* DepControl::getInstance(){
	if(instance == NULL){
		instance = new DepControl();
	}
	return instance;
}


bool DepControl::initialize(){

		if(g_hge->System_Initiate()){
			videoManager->init();
			deltaTime = 0.02f;
			exit = false;
		
			gameView = new GameView();
			return true;
		}else{
			return false;
		}
}


DepControl::~DepControl(){
	videoManager->release();
	g_hge->Release();
	delete gameView;
}

void DepControl::setMapSize(float width, float height){
	this->mapWidth = width;
	this->mapHeight = height;
}

void DepControl::setCameraViewSize(float cx, float cy){
	cameraViewX = cx;
	cameraViewY = cy;
}



DepControl::DepControl(){


	setMapSize(1200, 1200);
	setCameraViewSize(800, 600);//預設為營幕的中央
	setScreen(800, 600);
	setWindowMode(true);
	g_hge->System_SetState(HGE_FRAMEFUNC, frameFunc);
	g_hge->System_SetState(HGE_WINDOWED, true);
	g_hge->System_SetState(HGE_SHOWSPLASH, false);
	g_hge->System_SetState(HGE_USESOUND, false);
    g_hge->System_SetState(HGE_LOGFILE, "System_Log.Txt"); 
	g_hge->System_SetState(HGE_ZBUFFER, true);
	g_hge->System_SetState(HGE_DONTSUSPEND, true);
	g_hge->System_SetState(HGE_TITLE, "DEP game framework basing on HGE Engine(設計：地平線的彼端)");
	videoManager = new VideoManager();
	
}



void DepControl::resetGame(){
		gameView->resetGame();
		exit = false;
}


void DepControl::setTitle(char *title){
	g_hge->System_SetState(HGE_TITLE, title);	

}

void DepControl::setScreen(int width, int height){
	screenWidth = width;
	screenHeight = height;
    g_hge->System_SetState(HGE_SCREENWIDTH, width);
	g_hge->System_SetState(HGE_SCREENHEIGHT, height);
}

void DepControl::setFPS(int fps){
	    g_hge-> System_SetState(HGE_FPS, fps); 
}

void DepControl::setWindowMode(bool windowed){
   bWindowed = windowed;
   	// Screen Size 
   RECT   screenRect; 
   GetWindowRect (GetDesktopWindow(), & screenRect); 
   int mDesktopWidth = abs (screenRect.right - screenRect.left); 
   int mDesktopHeight = abs (screenRect.bottom - screenRect.top); 

   HWND handle = g_hge->System_GetState(HGE_HWND); 

   if (bWindowed){ 
      // Restore windowed mode 
      LONG nOldStyle = ::GetWindowLong (handle, GWL_STYLE); 
      ::SetWindowLong (handle, GWL_STYLE, nOldStyle | WS_CAPTION); 

	  ::SetWindowPos (handle, HWND_NOTOPMOST, (mDesktopWidth - screenWidth) / 2, (mDesktopHeight - screenHeight) / 2, 
         screenWidth + ::GetSystemMetrics (SM_CXBORDER) * 2, 
         screenHeight + ::GetSystemMetrics (SM_CYBORDER) * 2 + ::GetSystemMetrics (SM_CYCAPTION), 
         SWP_SHOWWINDOW); 
   } else { 
      // Remove window caption and resize to full screen 
      LONG nOldStyle = ::GetWindowLong (handle, GWL_STYLE); 
      ::SetWindowLong (handle, GWL_STYLE, nOldStyle & ~WS_CAPTION); 

     // ::SetWindowPos (handle, HWND_TOPMOST, 0, 0, mDesktopWidth, mDesktopHeight, SWP_SHOWWINDOW); 
	  ::SetWindowPos (handle, HWND_DESKTOP, 0, 0, mDesktopWidth, mDesktopHeight, SWP_SHOWWINDOW); 
   } 


}


void DepControl::run(){
	videoManager->handleEvent();
	gameView->Render();
}