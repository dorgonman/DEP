
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
	float sit;//�g�t
	float dsit;//�Z�W�@�o�l�u�o�g��g�L�h�֮ɶ�
	float AT, dAT;//�L�Įɶ��H�Ψ�g�L�h�֮ɶ�
	bool achillean;//�O�_�B��L�Ī��A

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
	float dt;//�ΨӧP�_�Q��������L�F�h�֮ɶ�
	float ht;//�w���ɶ�
	bool ishit;//�p�G��true�h�]���b�z���B�L�Ī��A�A�ö}�l�p��dt�A�b�g�L5���]�^false
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