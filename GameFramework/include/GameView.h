#include    "GameControl.h"
#include	<vector>
#include "hge.h"


#ifndef DEP_VIEW
#define DEP_VIEW


//�����O�t�d��{view������

class GameView {
public:
	GameView();
	~GameView();



public:
	void Render();
	void setGame(GameControl* game){
		gameControl = game;
	};
	void selectGame(int index);//�Ngame view�B�z�����d�]��games�}�C�����Y��index(�p�]���W�Lgames vector��index�h�|�]���}�C���̫�@��)
	void resetGame();
	void addGame(GameControl* game);

	

private:
	void mapRender();
	void radarRender();
	void loadSprite();

private:
hgeSprite*		cameraView;//���a���I
HTARGET			mapTarget;//�a�ϵe��
hgeSprite*		radarView;
HTARGET			radarTarget;//�p�F�e��
GameControl*	gameControl;
vector<GameControl*>	games;
};

#endif