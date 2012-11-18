#include "GameControl.h"
#include "DepControl.h"

GameControl::GameControl(){
	dt = 0;
	depControl = DepControl::getInstance();
	depControl->setGameMode(LOADING);
	setCameraPosition(0, 0);
	rm = new hgeResourceManager();

}

void GameControl::setCameraView(hgeSprite* view, float x, float y){ //�b���a�ϤW�A�Hcamera�����߬����I�����Ϫk
	static float px = (float) (DepControl::getInstance()->cameraViewX / 2);
	static float py = (float) (DepControl::getInstance()->cameraViewY / 2);
	static float mapWidth = (float)DepControl::getInstance()->mapWidth;
	static float mapHeight = (float)DepControl::getInstance()->mapHeight;
	//�`�@��9�غI��view����k
	if (x - px <= 0 && y - py <= 0){  //1.����B��x����ɤ�y�W��ɪ����k
		view->SetTextureRect(0, 0, px * 2, y + py * 2);
	}

	if((x - px <= 0) && ((y - py >= 0)  && (y + py <= mapHeight))){  //2.����B��x����ɪ����k
		view->SetTextureRect(0, y - py, px * 2, y + py); 
	}

		
	if (x - px <= 0 && y + py >= mapHeight){  //3.����B��x����ɤ�y�U��ɪ����k
		view->SetTextureRect(0, mapHeight - py * 2,  px * 2, mapHeight);
	}

	
	if (x - px >= 0 && y - py <= 0){ //4.����B��y�W��ɪ����k
		view->SetTextureRect(x - px, 0, x + px, py * 2);
	}



	if(x - px >= 0 && y - py >= 0 ){  //5.����B�󤤥��϶����I����k
		view->SetTextureRect(x - px, y - py, x + px, y + py); //�b���a�ϤW�A�H���a�������I�A�I���@�����X��
	}
	

	if ( x - px >= 0 && y + py >= mapHeight){//6.����B��Y�U��ɪ����k
		view->SetTextureRect(x - px, mapHeight - py * 2, x + px, mapHeight);
	}


	if((x + px >= mapWidth) && y - py <= 0){//7.������x�k��ɤ�y�W�ɪ����k
		view->SetTextureRect(mapWidth - px * 2, 0, mapWidth, py * 2);
	}

	if(x + px >= mapWidth && ((y - py >= 0) && (y + py <= mapHeight))){ //8.������x�k��ɪ����k
		view->SetTextureRect(mapWidth - px * 2, y - py, mapWidth, y + py);
	}

	if(x + px >= mapWidth && y + py >= mapHeight){ //9.������x�k��ɤ�y���U��ɨ��k
		view->SetTextureRect(mapWidth - px * 2, mapHeight - py * 2, mapWidth, mapHeight);
	}

}



void GameControl::setCameraPosition(float x, float y){
	cameraX = x;
	cameraY = y;
}


