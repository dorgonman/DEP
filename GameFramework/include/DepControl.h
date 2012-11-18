#include "GameView.h"
#include "hge.h"
#include "GlobalVariable.h"
#include "VideoManager.h"

#ifndef DEP_SYSTENCONTROL
#define DEP_SYSTENCONTROL


class DepControl{
public:
	bool bWindowed;
	float mapWidth;
	float mapHeight;
	int screenWidth;
	int screenHeight;
	float cameraViewX;
	float cameraViewY;
	void setMapSize(float width, float height);
	void setCameraViewSize(float cx, float cy);

private:
	    static DepControl* instance;
		GameView* gameView;
		VideoManager* videoManager;
		bool exit;
	    int	 gameMode;
		float  deltaTime; 
		//HGE* hge;


public:
	int getGameMode(){return gameMode;};
	void setGameMode(int _mode){gameMode = _mode;};
	bool initialize();
	void systemStart(){g_hge->System_Start();};
	void systemShutDown(){
		g_hge->System_Shutdown();
		g_hge->Release();
	};
protected:

	DepControl();
	~DepControl();

public:
		static DepControl* getInstance();
		void setExit(bool isExit){
			exit = isExit;
		};
		bool isExit(){return exit;};
		void run();


		void setGame(GameControl* game){
			gameView->setGame(game);
		};

		void selectGame(int index){
			setGameMode(GameControl::LOADING);
			gameView->selectGame(index);
		};
		void addGame(GameControl* game){
			gameView->addGame(game);
		};
		void resetGame();
		VideoManager* getVideoManager(){return videoManager;};

		//hge->Timer_GetDelta大概會是0.03~0.04間跳動，為使時間軸穩定故取0.02 deltaTime會是0.02
		float Timer_GetDelta(){
			return deltaTime;
		};


public://window method
	void setTitle(char* title);
	void setWindowMode(bool windowed);
	bool getWindowMode(){return bWindowed;};
	void setScreen(int width, int height);
	void setFPS(int fps);
};

#endif