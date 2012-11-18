#include "Stage.h"
#include "DepControl.h"
#include "Font.h"
#include "AIEngine.h"
#include "hgeVector.h"
#include <stdio.h>
#include <math.h>
#include "DEPSound.h"


static DEPSprite* c1;
 static DEPSound* sound = NULL;


AIEngine* ai;



//HGE* hge;
void Stage1::initialize(){
	
	c1 = new DEPSprite(g_rm->GetTexture(".\\Picture\\wafu1.png"), 0, 0, 800, 600);
	sound =  new DEPSound();
	enemySprs[0]->getGUN(0)->addBullet(0, 1000, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0 ,0, 45, 45);
	//hge = hgeCreate(HGE_VERSION);
}



//注意，當在設定sprite的時候，必須先設定alive再設定其他資訊，不然的話，有些資訊會被重設回預設值(每執行setAlive一次，就會將一些資訊設回預設值)
void Stage1::doLoadingScript(){

	sound->setStream(".\\bgm\\starlight_temple2.mp3");
	sound->playStream();
	//bgm = hge->Stream_Play(hge->Stream_Load(".\\bgm\\starlight_temple2.mp3"), true, 100);
	//bgSpr->SetTexture(rm->GetTexture(".\\Picture\\Stage\\stage4.png"));
	//bgSpr->SetTextureRect(0, 0, 1200, 1200);

	bgSpr->setPosition(0, 0);
	scriptMode = BATTLE;
	dt = 0;
	resetPlayer();

	int i = 0;
	for(i = 0; i < 1; i++){
		enemySprs[i]->setAlive(true);
		enemySprs[i]->setHP(100);
		enemySprs[i]->SetTexture(rm->GetTexture(".\\Picture\\character\\boss_suika.png"));
		enemySprs[i]->SetTextureRect(0, 0, 45, 60);
		enemySprs[i]->setSize(1, 1);
		enemySprs[i]->getGUN(0)->setAlive(true);
		enemySprs[i]->getGUN(0)->setPattern(1);
		enemySprs[i]->getGUN(0)->setBulletFlyTime(20);
		enemySprs[i]->getGUN(0)->setShootingTime(2);
		enemySprs[i]->getGUN(0)->setBulletVelocity(0);
		enemySprs[i]->setPosition(500, 400);
		enemySprs[i]->setVelocity(10, 10);
	}
	playerSpr->setVelocity(10, 10);
	playerSpr->setHP(100);
	enemySprs[0]->setPosition(600, 600);

}






/*字型外框
方法很多..
1. 畫2次..1次大1次小
2. 畫5次 上下左右中
3. gdi..繪框..慢不過質好
    (gdi繪框線方法有像有2種)
*/


void Stage1::doBattleScript(){

	StageControl::doBattleScript();


	Font* fnt = GlobalVariable::getInstance()->getTTF();
	

	int i = 0;
	for(i = 0; i < 1; i++){
		ai->randomSearch(enemySprs[i]);
		ai->runToTarget(enemySprs[i]);
	}
	//enemySe->trace(enemySprs[0]->getGUN(0), playerSprs);
	g_hge->Gfx_RenderLine(enemySprs[0]->x - 200, enemySprs[0]->y, enemySprs[0]->x + 200, enemySprs[0]->y , 0xFFFF4422);
	
	GUN* gun = enemySprs[0]->getGUN(0);



	//ai->searchTarget(enemySprs[0], playerSpr, 50);
//	ai->randomSearch(enemySprs[0]);
	//ai->runCircle(playerSpr, enemySprs[0], 200, 0, 90);
	
	float dist;
	
	hgeTTF::Font* font = GlobalVariable::getInstance()->getTTF();
	font->setColor(0xFFFF0000);
	font->printf(playerSpr->x, playerSpr->y+50, L"x:%f y:%f", enemySprs[0]->x, enemySprs[0]->y);
	font->printf(playerSpr->x, playerSpr->y+100, L"x:%f y:%f", playerSpr->x, playerSpr->y);
	if(ai->distancePointLine(playerSpr->x, playerSpr->y, 
							 enemySprs[0]->x - 200, enemySprs[0]->y, 
							 enemySprs[0]->x + 200,  enemySprs[0]->y, &dist)){

		font->printf(playerSpr->x, playerSpr->y, L"fall in segment:%f", dist);
		if(dist >= 0 && dist <= 2){
			playerSpr->hpDown(100);
		}

	}
			

	static float tt = 0;
	tt += g_hge->Timer_GetDelta();

	if((int) tt % 10 == 5){
		enemySprs[0]->getGUN(0)->setPosition(enemySprs[0]->x - 200, enemySprs[0]->y);
		enemySprs[0]->getGUN(0)->setTargetPosition(enemySprs[0]->x , enemySprs[0]->y);
		enemySprs[0]->getGUN(0)->setShootingTime(0.02f);
		enemySprs[0]->getGUN(0)->setBulletVelocity(20);
		for(i = 0; i < 200; i++){
			gun->update();
			enemySe->trigger(gun);		
			ai->runToTarget(gun);
		}

		enemySe->trace(gun, playerSpr, 1000);
		tt++;
	}else{
			enemySprs[0]->getGUN(0)->setShootingTime(20);
			enemySprs[0]->getGUN(0)->setBulletVelocity(1, 10);
	}

	if( dt == 10){
		scriptMode = STORY;
		dt = 0;
	}


	if(!enemySprs[0]->isAlive()){
		doFinishScript();
	}



}

void Stage1::doStoryScript(){
	if(g_hge->Input_KeyDown(HGEK_ENTER)){
		dt+= 1;
	}
	if((int) dt == 0){
		dt += 1;
		playerSpr->setTargetPosition(600, 700);
	}
	if((dt > 1) &&( dt < 6)){
		dt += 0.02f;
		ai->runToTarget(playerSpr);
	}

	if((int)dt == 6 ){
		playerSpr->setPosition(600, 700);
	}

}


void Stage1::doFinishScript(){
	DepControl::getInstance()->selectGame(2);//選擇要連接的下一關卡
	sound->stopStream();
	//sound->stopStream();
}




void Stage1::doScreenScript(){
	static float cx = 0;
	static float cy = 0;
	static float f = 0 + 0.2f;
	f +=  0.2f;

	hgeTTF::Font* font = GlobalVariable::getInstance()->getTTF();
	font->printf(200, 300,  L"float:%f", f);

	snowEffectAt(300, -70);

   // snowEffectAt(300, 300, 300);

	StageControl::doScreenScript();



//	setCameraPosition(cx++, cy++);
	if(scriptMode == STORY){

		if((int) dt == 6 ){
	        c1->setSize(0.5f, 0.5f);
			c1->setPosition(0,0);
			font->setSize(40);
	     	font->printf(200, 500,  L"中文測試中ゾゾゾ 日本語パザわペソ？");

		}
		//c1->RenderEx();
		if((int) dt == 7 ){
			font->setColor(0xffcc0000);
						font->setSize(40);
			font->drawString(L"真是\t\nLine\v\n糟糕", 150, 200);
		}
		if((int) dt == 8 ){
						font->setSize(40);
			font->printf(200, 500,  L"真的可行嗎？");

		}
		if((int) dt > 8 ){
						font->setSize(40);
			font->printf(200, 500,  L"不試試看不知道");
			//scriptMode = BATTLE;
			dt = 11;
		}
	}


	





}

