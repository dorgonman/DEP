#include "StageControl.h"

#include "DepControl.h"
#include "StageResource.h"

#pragma comment(lib, "hge.lib")
#pragma comment(lib, "hgehelp.lib")

StageControl::StageControl() : GameControl(){
		res = StageResource::getInstance();
		bgSpr = new DEPSprite(NULL, 0, 0, 0, 0);
		playerSprs = res->mapSpr[0];
		playerSpr = playerSprs[0];
		enemySprs = res->mapSpr[1];
		gui = res->gui;



		enemySe = new ShootEngine();
		enemySe->setSoundEffect(ShootEngine::HIT, ".\\sounds\\reflect.wav");
		enemySe->setSoundEffect(ShootEngine::TRIGGER,".\\sounds\\se_sub01.wav");
		enemySe->setSoundEffect(ShootEngine::DIE, ".\\sounds\\bigshot1.wav");
		playerSe = new ShootEngine();
		playerSe->setSoundEffect(ShootEngine::HIT, ".\\sounds\\piko1.wav");
		playerSe->setSoundEffect(ShootEngine::TRIGGER, ".\\sounds\\tama2.wav");
		playerSe->setSoundEffect(ShootEngine::DIE, ".\\sounds\\BubbleB@16.wav");

		itemSe = new ItemEngine();
		itemSe->setSoundEffect(ItemEngine::GET, ".\\sounds\\get1.wav");
		ai = new AIEngine();
		scriptMode = BATTLE;
		//redirectIOToConsole();//此行執行之後，鍵盤的控制權會在CONSOLE，因此要先點一下CONSOLE再點回視窗INPUT才會有反應
		

}


StageControl::~StageControl(){

}



void StageControl::renderPointSpr(){
	static DEPSprite pointSpr(g_rm->GetTexture(".\\Picture\\point.png"), 0, 0, 45, 45);
	pointSpr.setSize(2, 2);
	pointSpr.SetHotSpot();
	

	pointSpr.setColor(0xFF00FF00);
	pointSpr.setPosition(playerSpr->x, playerSpr->y);
	pointSpr.RenderEx();


	pointSpr.setColor(0xFFEE0000);
	vector<RoleSprite*>::iterator it;
	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
		RoleSprite* enemySpr = *it;	
		if(enemySpr->isAlive()){
			pointSpr.setPosition(enemySpr->x, enemySpr->y);
			pointSpr.RenderEx();
		}
	}

}

void StageControl::doRenderScript(){
	

	bgSpr->RenderEx();
	RoleEngine::render(playerSprs);
	RoleEngine::render(enemySprs);


	static BAR hpBar(45, 45,  0xFF11FF00);
	static BAR MHPBar(45, 45, 0xFFBB0000);
	MHPBar.setLength(1);
	hpBar.setLength(playerSpr->getHP() / playerSpr->getMHP());
	MHPBar.Render(playerSpr->x, playerSpr->y);
	hpBar.Render(playerSpr->x, playerSpr->y);


	vector<RoleSprite*>::iterator it;
	for( it = enemySprs.begin(); it != enemySprs.end(); it++ ){
		RoleSprite* enemySpr = *it;	
		if(enemySpr->isAlive()){
			hpBar.setLength(enemySpr->getHP() / enemySpr->getMHP());
			MHPBar.Render(enemySpr->x, enemySpr->y);
			hpBar.Render(enemySpr->x, enemySpr->y);
		}
	}

}

void StageControl::doMainLoopScript(){
	static char tt[50];
	//電腦數值計算並不精確，故浮點數運算完後還要再做處理(四捨五入產生的問題)
	sprintf_s(tt, 50, "%.2f", dt);
	dt = atof(tt);

	if(scriptMode == BATTLE){
		doBattleScript();
		//電腦數值計算並不精確，故浮點數運算完後還要再做處理(四捨五入產生的問題)
		dt += depControl->Timer_GetDelta();//hge->Timer_GetDelta大概會是0.03~0.04間跳動，為使時間軸穩定故取0.02
	}

	if(scriptMode == STORY){
		doStoryScript();
	}

}

void StageControl::doBattleScript(){
	RoleEngine::update(playerSprs);
	RoleEngine::update(enemySprs);
	playerSe->trace(playerSpr->getGUN(2), enemySprs);
	playerSe->hit(playerSpr, enemySprs);
	processBattleInput();
	enemySe->hit(enemySprs, playerSpr);
	enemySe->trigger(enemySprs);
	itemSe->check(enemySprs, playerSpr);
	itemSe->check(playerSprs, enemySprs);
	itemSe->check(playerSprs, playerSprs);
	itemSe->runToTarget(playerSprs);
	itemSe->runToTarget(enemySprs);
}



void StageControl::doScreenScript(){
	GameControl::doScreenScript();
	setCameraPosition(playerSpr->x, playerSpr->y);
	hgeTTF::Font* fnt = GlobalVariable::getInstance()->getTTF();
	fnt->setSize(20);
	fnt->setColor(0xFFFFFFFF);
	fnt->printf(10, 40, L"dt:%.2f", dt);
	gameEffect();
	if(scriptMode == BATTLE ){
		static DEPSprite* mask = new DEPSprite(g_rm->GetTexture(".\\Picture\\mask.png"), 0, 0, 800, 600);
		mask->setAphabate(0xAA);
		if(GlobalVariable::getInstance()->isStop()){
			mask->Render(0, 0);
		}
		renderGameInformation();
		BattleGUIFunction();
	}

	if(g_hge->Input_KeyDown(HGEK_GRAVE)){		
		doFinishScript();
	}
}




void StageControl::resetGame(){
	clearEnemy();
	dt = 0;
	resetPlayer();
	depControl->setGameMode(LOADING);

}