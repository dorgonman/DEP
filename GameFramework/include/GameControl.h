#include "hgeSprite.h"
#include <vector>
#include "hgeResource.h"
using namespace std;


#ifndef DEP_GAME
#define DEP_GAME
class DepControl;


class GameControl{

public:
	GameControl();
	~GameControl(){
		 delete radarView;
		 delete cameraView;
	};

	void gameUpdate(hgeSprite* cameraView);
	void screenUpdate();
	virtual void doRenderScript(){};
	virtual void renderPointSpr(){};

private://gameUpdate系統公用邏輯函式
	void doGameScript();

	
protected://hook method

	virtual void doLoadingScript();
	virtual void doMainLoopScript(){};
	virtual void doScreenScript();


	

public:
	virtual void resetGame(){};

public:
	static enum GameMode{ //script模式
	   LOADING = 0,
	   MAINLOOP = 1,
	 }; 

public:
	void setRadarView(hgeSprite* _radarView){radarView = _radarView;};
	void setCameraView(hgeSprite* _cameraView){cameraView = _cameraView;};

private:
	void setCameraView(hgeSprite* view, float x, float y);
	float cameraX, cameraY;
protected:
	void setCameraPosition(float x, float y);
	hgeSprite*          radarView;
	hgeSprite*          cameraView;
	DepControl*    depControl;
	hgeResourceManager* rm;
	double dt;


};




#endif