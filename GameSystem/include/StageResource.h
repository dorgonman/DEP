#include "RoleSprite.h"
#include <vector>
#include <map>
#include "hgeGUI.h"
#include "hgeParticle.h"
#ifndef DEP_STAGERESOURCE
#define DEP_STAGERESOURCE


class StageResource{
public:
	StageResource();
	~StageResource();

public:
	map<int, vector<RoleSprite*>> mapSpr;
	hgeGUI* gui;
	vector<hgeParticleSystem*> pars;

	static enum GUIState{ //GUI¼Ò¦¡
       CONTINUE = 1, 
       GIVEUP = 2,
	   YES = 3,
	   NO = 4
	 }; 

	
private:
	    static StageResource* instance;
		void playerLoad();
		void enemyLoad();
		void GUISetting();
		void particleLoad();
		
public:
		static StageResource* getInstance();
		void addItem(RoleSprite* roleSpr, int amount);
};
#endif