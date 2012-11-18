#include "GameControl.h"
#include "GameVariable.h"
#include "RoleEngine.h"
#include "GlobalVariable.h"
#include "hgeGUI.h"
#include <vector>
#include "StageResource.h"

using namespace std;
#ifndef DEP_STAGECONTROL
#define DEP_STAGECONTROL


class StageControl:public GameControl{
public:
	StageControl();
	~StageControl();

protected:
	void shockView(bool b, float v = 0, float w = 0);
	void renderViewEx(bool b, float rot = 0, float vscale = 0, float wscale = 0);
	void snowEffectAt(float x, float y, int amount = 300, float minGravity = 10, float maxGravity = 40);
protected:
	void resetPlayer();
	
	void doMainLoopScript();
	static enum ScriptMode{ //script¼Ò¦¡
	  BATTLE = 3,
	  STORY = 4
	 }; 
	int scriptMode;
protected://hook method
	virtual void doRenderScript();
	virtual void doScreenScript();
	virtual void renderPointSpr();
	virtual void resetGame();


	virtual void doBattleScript();
	virtual void doStoryScript(){};
	virtual void doFinishScript(){};


private:
	void gameEffect();
	void processBattleInput();


private:
	void BattleGUIFunction();
	void renderGameInformation();
	void clearEnemy();



public:
	void setGUI_ID(int _id){id = _id;}
protected:
	vector<RoleSprite*> playerSprs;
	vector<RoleSprite*> enemySprs;
	RoleSprite* playerSpr;
	RoleSprite* enemySpr;
	DEPSprite* bgSpr;
	ShootEngine* enemySe;
	ShootEngine* playerSe;
	ItemEngine* itemSe;
	GUN* playerGUN;
protected:
	StageResource* res;
	AIEngine* ai;
	hgeGUI*				gui;
	wchar_t		guiInfor[100];
	int id;








};

#endif




