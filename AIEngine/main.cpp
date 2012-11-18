/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hge_tut03 - Using helper classes
*/


// Copy the files "particles.png", "menu.wav",
// "font1.fnt", "font1.png" and "trail.psi" from
// the folder "precompiled" to the folder with
// executable file. Also copy hge.dll and bass.dll
// to the same folder.


#include "hge.h"
#include "DEPSprite.h"
#include "AIEngine.h"
#include "IOSTREAM"


// Pointer to the HGE interface.
// Helper classes require this to work.




DEPSprite* playerSpr;
DEPSprite* enemySpr;
DEPSprite* tileSpr;
HTEXTURE tex;
AIEngine* ai;
HGE* hge;


	//_CrtMemDumpAllObjectsSince(NULL);
   // _CrtDumpMemoryLeaks();  //用這個比較簡單



void playerInput(){
	int baseX = 20;
	int baseY = 20;
	if (hge->Input_GetKeyState(HGEK_LEFT)){ 
		if(ai->GetGridMapContent(playerSpr->x - baseX, playerSpr->y) != WALL){		
			playerSpr->runLeft();
		}else{
			if (hge->Input_GetKeyState(HGEK_UP)){
				if(ai->GetGridMapContent(playerSpr->x - baseX, playerSpr->y - baseY) != WALL){	
					playerSpr->runLeft();
					playerSpr->runUp();
				}
			}

			if (hge->Input_GetKeyState(HGEK_DOWN)){
				if(ai->GetGridMapContent(playerSpr->x - baseX, playerSpr->y + baseY) != WALL){	
					playerSpr->runLeft();
					playerSpr->runDown();
				}
			}
		}

	}
	if (hge->Input_GetKeyState(HGEK_RIGHT)){
		if(ai->GetGridMapContent(playerSpr->x + baseX, playerSpr->y) != WALL){		
			playerSpr->runRight();
		}else{
			if (hge->Input_GetKeyState(HGEK_UP)){
				if(ai->GetGridMapContent(playerSpr->x + baseX, playerSpr->y - baseY) != WALL){	
					playerSpr->runRight();
					playerSpr->runUp();
				}
			}

			if (hge->Input_GetKeyState(HGEK_DOWN)){
				if(ai->GetGridMapContent(playerSpr->x + baseX, playerSpr->y + baseY) != WALL){	
					playerSpr->runRight();
					playerSpr->runDown();
				}
			}
		
		}
	}

	if (hge->Input_GetKeyState(HGEK_UP)){   
		if(ai->GetGridMapContent(playerSpr->x, playerSpr->y - baseY) != WALL){		
			playerSpr->runUp();
		}
	}
	if (hge->Input_GetKeyState(HGEK_DOWN)){
		if(ai->GetGridMapContent(playerSpr->x, playerSpr->y + baseY) != WALL){		
			playerSpr->runDown();
		}
	}





}
bool FrameFunc(){
	float dt=hge->Timer_GetDelta();
	playerSpr->update();
	enemySpr->update();
	
	if(ai->runAstarPath(enemySpr) == false){//當到達目的地時
	ai->astarPathSearch(enemySpr, hge->Random_Float(0, 800), hge->Random_Float(0, 600));
	}

	ai->runSpiral(playerSpr, enemySpr, 5, 200, 1000.0f, -5);
	playerInput();


	//ai->astarPathSearch(560, 180, 560, 420);

	



	//ai->searchTarget(enemySpr,500,500, 1000);
	//ai->runToTarget(enemySpr);


	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	int i; 
	int j;
	for(i = 0; i < GRID_X; i++){
		for(j = 0; j <GRID_Y;j++){
			if(GridMap[i][j] == WALL){
				tileSpr->setPosition(i* 80, j* 60);
				tileSpr->RenderEx();
			}
		}
	}

	ai->renderAstarPath(tex);

	playerSpr->RenderEx();
	enemySpr->RenderEx();


	hge->Gfx_EndScene();

	return false;
}
void testAI(){
	playerSpr = new DEPSprite(hge->Texture_Load(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
	playerSpr->setPosition(0, 0);
	playerSpr->SetHotSpot();
	//playerSpr->setVelocity(1,1);

	enemySpr = new DEPSprite(hge->Texture_Load(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
	enemySpr->SetHotSpot();

	tex = hge->Texture_Load(".\\Picture\\point2.png");
	tileSpr = new DEPSprite(tex, 0, 0, 80, 60);
	tex = hge->Texture_Load(".\\Picture\\astarPoint.png");
	//tileSpr->SetHotSpot(0,0);
	ai = new AIEngine();
	ai->setMapRange(0, 0, 800, 600);
	ai->GetGridMapContent(playerSpr->x , playerSpr->y);

	//set start and goal node:00 to 91 
	//if the goal node can't reach, we will find the path will go to last search node
	//may be we can design a mechanism, 
	//and improving a* algorithm that will find the best reaching route nearest goal node

	enemySpr->setPosition(0, 0);
	ai->astarPathSearch(enemySpr, 720, 70);
	
	//00 99
	//ai->astarPathSearch(0, 0, 780, 580);

}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "DEP AIEngine");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_DONTSUSPEND, true);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_SHOWSPLASH, false);
	redirectIOToConsole();

	if(hge->System_Initiate()) {

		// Load sound and texture
		testAI();
		// Let's rock now!
		hge->System_Start();


	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
