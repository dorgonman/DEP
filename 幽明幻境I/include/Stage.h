#include "StageControl.h"

#ifndef DEP_STAGE
#define DEP_STAGE


class StageTitle :public StageControl{
public:
	StageTitle():StageControl(){
		initialize();
	};

private:
	void doScreenScript();
	void doLoadingScript();
	void doStoryScript();
	void doFinishScript();
	void initialize();

};


class Config : public StageControl{
	Config();
private:
	void doScreenScript();
};



class Stage1 :public StageControl{
public:
	Stage1():StageControl(){						
		initialize();
	};
private:
	void doLoadingScript();
	void doBattleScript();
	void doStoryScript();
	void doFinishScript();
	void initialize();
public:
	void doScreenScript();
private://關卡的公用函式
	void setEvent1();
	void doEvent1();
	void setEvent2();
	void doEvent2();
};


class StageExtra:public StageControl{
public:
	StageExtra():StageControl(){
		initialize();
	};
private:
	void doLoadingScript();
	void doBattleScript();
	void doStoryScript();
	void doFinishScript();
	void initialize();
	void enemyLoad();
public:
	void doScreenScript();

private://關卡的公用函式
	void setEvent1();
	void doEvent1();
	float theta1;
	float theta2;
	float theta3;
	float theta4;
	

};
#endif