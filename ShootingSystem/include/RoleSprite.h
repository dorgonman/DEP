
#include "DEPSprite.h"
#include "GUN.h"
#include "Item.h"
#include "BAR.h"
#include <vector>
using namespace std;
#ifndef DEP_ROLE
#define DEP_ROLE


//=================================RoleSprite===============================

class Item;

class RoleSprite:public DEPSprite{
public:
	RoleSprite(HTEXTURE _tex,  float _x, float _y, float _w, float _h) : 
	  DEPSprite(_tex,  _x, _y, _w, _h){
		  initialize();
	  };
	~RoleSprite(){
		  delete hitPoint;
		  vector<GUN*>::iterator it;
		  for(it = guns.begin(); it != guns.end() ; it++){
			GUN* gun = *it;
			delete gun;
		  }
	  }


	 virtual bool hpDown(float attack);
	 virtual void RenderEx();
	 virtual void update();
	 void setAlive(bool _alive);
	 void setHP(float _HP){
		 MHP = _HP;
		 HP = _HP;
	 };
	 float getHP(){return HP;}; 
	 virtual void setHT(float _ht){};
	 virtual float getHT(){return 0;};
	 virtual void checkEffectTime(){};
	 virtual bool isHit(){return false;};
	 virtual void addHP(float HP);
	 virtual void setAchillean(bool b){achillean = b;};
	 virtual bool getAchillean(){return achillean;};
	 virtual float getAT(){return AT;};
	 virtual void setAT(float _AT){AT = _AT;};
	 void setdAT(float _dAT){dAT = dAT;};
	 float getMHP(){return MHP;};


public://item system
     vector<Item*> getItems();
	 void addItem(Item* i);
public://shooting system
	void setGUN(int i, GUN* newGun);
	GUN* getGUN(int i);
	void addGUN(GUN* newGun);
	vector<GUN*> getGUNS(){return guns;};




private:
	void initialize();
protected:
	vector<GUN*> guns;

	vector<Item*>	   items;
	float HP, MHP;
	int power;
	float sit;//射速
	float dsit;//距上一發子彈發射後經過多少時間
	float AT, dAT;//無敵時間以及其經過多少時間
	bool achillean;//是否處於無敵狀態

};


class PlayerSprite:virtual public RoleSprite{
public:
	PlayerSprite(HTEXTURE _tex,  float _x, float _y, float _w, float _h) : RoleSprite(_tex,  _x, _y, _w, _h){
		this->initialize();
		
	};
	bool hpDown(float attack);;
	void setHT(float _ht){ht = _ht;};
	float getHT(){return ht;};
	void checkEffectTime();
	bool isHit(){return ishit;};

	
public:
	~PlayerSprite(void){};
private:
	void initialize();
	void setDirection();

private:
	float dt;//用來判斷被擊中之後過了多少時間
	float ht;//硬直時間
	bool ishit;//如果為true則設為半透明、無敵狀態，並開始計算dt，在經過5秒後設回false
};




class EnemySprite:virtual public RoleSprite{
public:
	EnemySprite(HTEXTURE _tex,  float _x, float _y, float _w, float _h) : RoleSprite(_tex,  _x, _y, _w, _h){
		initialize();
	};
	void hpDown();

private:
	void initialize();
};





#endif


//=================================================================