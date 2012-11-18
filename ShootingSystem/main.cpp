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
#include "ShootEngine.h"
#include "RoleSprite.h"
#include "AIEngine.h"
#include "hgeResource.h"
#include "ItemEngine.h"
#include "RoleEngine.h"
#include <vector>
using namespace std;


// Pointer to the HGE interface.
// Helper classes require this to work.

HGE* hge;
hgeResourceManager* rm;
vector<RoleSprite*> playerSprs;
RoleSprite* playerSpr;
RoleSprite* enemySpr;
AIEngine* ai;
ShootEngine* enemySe;
ShootEngine* playerSe;
GUN* gun;
Bullet* bullet;
BAR* bar;
ItemEngine* ie;

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();
	if (hge->Input_GetKeyState(HGEK_LEFT)) playerSpr->runLeft();
	if (hge->Input_GetKeyState(HGEK_RIGHT)) playerSpr->runRight();
	if (hge->Input_GetKeyState(HGEK_UP)) playerSpr->runUp();
	if (hge->Input_GetKeyState(HGEK_DOWN)) playerSpr->runDown();

	RoleEngine::update(playerSpr);
	RoleEngine::update(enemySpr);


	ai->randomSearch(enemySpr);
	ai->runToTarget(enemySpr);


	enemySe->trace(playerSpr->getGUN(0), enemySpr);

	enemySe->hit(playerSpr, enemySpr);
	enemySe->trigger(playerSpr);
	ie->check(enemySpr, playerSpr);

	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	RoleEngine::render(playerSpr);
	RoleEngine::render(enemySpr);

	hge->Gfx_EndScene();

	return false;
}



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE Tutorial 03 - Using helper classes");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_SHOWSPLASH, false);

	if(hge->System_Initiate()) {
		rm = new hgeResourceManager();
		// Load sound and texture
		playerSpr = new PlayerSprite(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
		playerSpr->SetHotSpot();
		playerSpr->setAlive(true);
		enemySpr = new RoleSprite(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45);
		enemySpr->setAlive(true);
		ai = new AIEngine();
		enemySpr->setHP(1000);
		enemySpr->SetHotSpot();
		GUN* gun = new ThetaGUN(rm->GetTexture(".\\defaultPic.png"), 0, 0, 45, 45);
		gun->setAlive(true);
		gun->addBullet(gun->PicDirect, 20, rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
		gun->setShootingTime(0.2f);
		gun->setBulletFlyTime(0.5f);
		playerSpr->addGUN(gun);
		playerSprs.push_back(playerSpr);

		
		enemySe = new ShootEngine();
		enemySe->setSoundEffect(ShootEngine::HIT, ".\\sounds\\reflect.wav");
		enemySe->setSoundEffect(ShootEngine::TRIGGER, ".\\sounds\\se_sub01.wav");
		enemySe->setSoundEffect(ShootEngine::DIE, ".\\sounds\\bigshot1.wav");
		playerSe = new ShootEngine();
		playerSe->setSoundEffect(ShootEngine::HIT, ".\\sounds\\piko1.wav");
		playerSe->setSoundEffect(ShootEngine::TRIGGER, ".\\sounds\\tama2.wav");
		playerSe->setSoundEffect(ShootEngine::DIE, ".\\sounds\\BubbleB@16.wav");

		ie = new ItemEngine();
		ie->setSoundEffect(ItemEngine::GET, ".\\sounds\\get1.wav");
		enemySpr->addItem(new Item(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45));
		enemySpr->addItem(new Item(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45));
		enemySpr->addItem(new Item(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45));
		enemySpr->addItem(new Item(rm->GetTexture(".\\Picture\\character\\toutetsuSD.png"), 0, 0, 45, 45));


	
		// Let's rock now!
		hge->System_Start();


	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
