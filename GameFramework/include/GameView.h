#include    "GameControl.h"
#include	<vector>
#include "hge.h"


#ifndef DEP_VIEW
#define DEP_VIEW


//此類別負責顯現view的部份

class GameView {
public:
	GameView();
	~GameView();



public:
	void Render();
	void setGame(GameControl* game){
		gameControl = game;
	};
	void selectGame(int index);//將game view處理的關卡設成games陣列中的某個index(如設成超過games vector的index則會設成陣列的最後一個)
	void resetGame();
	void addGame(GameControl* game);

	

private:
	void mapRender();
	void radarRender();
	void loadSprite();

private:
hgeSprite*		cameraView;//玩家視點
HTARGET			mapTarget;//地圖畫布
hgeSprite*		radarView;
HTARGET			radarTarget;//雷達畫布
GameControl*	gameControl;
vector<GameControl*>	games;
};

#endif