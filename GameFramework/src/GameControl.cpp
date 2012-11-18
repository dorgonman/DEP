#include "GameControl.h"
#include "DepControl.h"

GameControl::GameControl(){
	dt = 0;
	depControl = DepControl::getInstance();
	depControl->setGameMode(LOADING);
	setCameraPosition(0, 0);
	rm = new hgeResourceManager();

}

void GameControl::setCameraView(hgeSprite* view, float x, float y){ //在全地圖上，以camera為中心為視點的取圖法
	static float px = (float) (DepControl::getInstance()->cameraViewX / 2);
	static float py = (float) (DepControl::getInstance()->cameraViewY / 2);
	static float mapWidth = (float)DepControl::getInstance()->mapWidth;
	static float mapHeight = (float)DepControl::getInstance()->mapHeight;
	//總共有9種截取view的方法
	if (x - px <= 0 && y - py <= 0){  //1.角色處於x左邊界及y上邊界的取法
		view->SetTextureRect(0, 0, px * 2, y + py * 2);
	}

	if((x - px <= 0) && ((y - py >= 0)  && (y + py <= mapHeight))){  //2.角色處於x左邊界的取法
		view->SetTextureRect(0, y - py, px * 2, y + py); 
	}

		
	if (x - px <= 0 && y + py >= mapHeight){  //3.角色處於x左邊界及y下邊界的取法
		view->SetTextureRect(0, mapHeight - py * 2,  px * 2, mapHeight);
	}

	
	if (x - px >= 0 && y - py <= 0){ //4.角色處於y上邊界的取法
		view->SetTextureRect(x - px, 0, x + px, py * 2);
	}



	if(x - px >= 0 && y - py >= 0 ){  //5.角色處於中央區塊的截取方法
		view->SetTextureRect(x - px, y - py, x + px, y + py); //在全地圖上，以玩家為中心點，截取一部份出來
	}
	

	if ( x - px >= 0 && y + py >= mapHeight){//6.角色處於Y下邊界的取法
		view->SetTextureRect(x - px, mapHeight - py * 2, x + px, mapHeight);
	}


	if((x + px >= mapWidth) && y - py <= 0){//7.角色位於x右邊界及y上界的取法
		view->SetTextureRect(mapWidth - px * 2, 0, mapWidth, py * 2);
	}

	if(x + px >= mapWidth && ((y - py >= 0) && (y + py <= mapHeight))){ //8.角色位於x右邊界的取法
		view->SetTextureRect(mapWidth - px * 2, y - py, mapWidth, y + py);
	}

	if(x + px >= mapWidth && y + py >= mapHeight){ //9.角色位於x右邊界及y的下邊界取法
		view->SetTextureRect(mapWidth - px * 2, mapHeight - py * 2, mapWidth, mapHeight);
	}

}



void GameControl::setCameraPosition(float x, float y){
	cameraX = x;
	cameraY = y;
}


