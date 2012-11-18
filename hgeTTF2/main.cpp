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
//#include "DEPSprite.h"
//#include "AIEngine.h"
#include "FontManager.h"
#include "Font.h"
using namespace hgeTTF;
// Pointer to the HGE interface.
// Helper classes require this to work.



/*DEPSprite* playerSpr;
DEPSprite* enemySpr;
AIEngine* ai;*/
HGE* hge;
FontManager* FontMgr;
Font* font;
bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	/*playerSpr->update();
	enemySpr->update();

	if (hge->Input_GetKeyState(HGEK_LEFT)) playerSpr->runLeft();
	if (hge->Input_GetKeyState(HGEK_RIGHT)) playerSpr->runRight();
	if (hge->Input_GetKeyState(HGEK_UP)) playerSpr->runUp();
	if (hge->Input_GetKeyState(HGEK_DOWN)) playerSpr->runDown();
	ai->randomSearch(enemySpr);
	ai->runToTarget(enemySpr);*/

	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	/*playerSpr->RenderEx();
	enemySpr->RenderEx();*/
	font->drawString(L"哈哈哈\nXXXX", 100, 100);



	hge->Gfx_EndScene();

	return false;
}
void testAI(){
	//playerSpr = new DEPSprite(hge->Texture_Load(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
	//enemySpr = new DEPSprite(hge->Texture_Load(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
	//ai = new AIEngine();

}

void testTTF(){
	FontMgr = new FontManager();
	FontMgr->Initialize();
	FontMgr->loadFont("mona.ttf");
	font = FontMgr->getFont("mona.ttf");
	font->setSize(32);
	font->cacheChars('a', 'z');
	font->cacheChars(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

}



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "DEP AIEngine");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_DONTSUSPEND, true);//我把bass拿掉了~~~~~所以要設成false
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);


	if(hge->System_Initiate()) {

		// Load sound and texture
		//testAI();

		testTTF();

	

		// Let's rock now!
		hge->System_Start();


	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
