#pragma once
#include "hgeanim.h"
#include "hge.h"
#include  "hgeresource.h"
#include "hgerect.h"
#include <string>
#include "HitPoint.h"
#include "AIEngine.h"



#ifndef DEP_SPRITE
#define DEP_SPRITE


void redirectIOToConsole( void );


static hgeResourceManager* g_rm = new hgeResourceManager();
class DEPSprite{
	
public:
	DEPSprite(HTEXTURE tex, float x, float y, float w, float h, int nframe = 1, float fps = 10);

	 ~DEPSprite();

public://picture

	 hgeRect* GetBoundingBox(){
		 return spr->GetBoundingBox(this->x, this->y, new hgeRect());
	 };
	 hgeRect* GetBoundingBoxEX(float x, float y, float rot, float hscale, float vscale, hgeRect* rect){return spr->GetBoundingBoxEx(x, y, rot, hscale, vscale, new hgeRect()); };
	 DWORD getColor(){return spr->GetColor();};
	 virtual void RenderEx();
	 virtual void Render(float _x, float _y){
		 spr->Render(_x, _y);};

	 void RenderEx(float x, float y, float rot, float hscale = 1.00000, float vscale = 1.00000){
		 spr->RenderEx(x, y, rot, hscale, vscale);
	 }
	 void setAphabate(DWORD a){
		 spr->SetColor(SETA(spr->GetColor(), a));//設透明色
	 };
	 void setBlendMode(int blend){spr->SetBlendMode(blend);};
	 void setColor(DWORD col){
		 spr->SetColor(col);
	 };
	 void SetFlip(bool bX, bool bY, bool bHotSpot = false){spr->SetFlip(bX, bY, bHotSpot);};
	 void SetHotSpot(){spr->SetHotSpot(w / 2, h / 2);};
	 void SetHotSpot(float _x, float _y){spr->SetHotSpot(x, y);};

	 void setPicRotationTheta(float _rtheta){
		 double PI = 3.14159; 
		 rot = _rtheta * (float)(PI / 180);
	 };
	 void setSize(float _hscale, float _vscale){
		 hscale = _hscale;
		 vscale = _vscale;
	 };
	void SetTexture(HTEXTURE _tex);
	void SetTextureRect(float x, float y, float w, float h, bool adjSize = true);
	HitPoint* getHitPoint(){return hitPoint;};
	void setHitRadius(float _r){
		hitPoint->setHitRadius(_r);
	};
	void setAI(AIEngine* _ai);
	AIEngine* getAI();
	hgeSprite* getSprite(){return spr;};


	

public://behavior
	float getVelocityX(){return velocityX;};
	float getVelocityY(){return velocityY;};
	void setVelocity(float _velocityX, float _velocityY = 3);

	void setPosition(float _x, float _y);

	void setTargetPosition(float tx, float ty){
		targetX = tx;
		targetY = ty;
	};
	void setTheta(float _theta){theta = _theta;};
	float getTheta(){return theta;};
	virtual void setAlive(bool _alive);
	bool isAlive(){return alive;};
	virtual void update();

public://animation
	void replayAnime(){spr->Play();};
	void stopAnime(){spr->Stop();};
	void resumeAniem(){spr->Resume();};
	int getFrame(){spr->GetFrame();};
	int getFrames(){spr->GetFrames();};
	int getAnimeMode(){spr->GetMode();};
	float getAnimeSpeed(){spr->GetSpeed();};
	void setAnimeMode(int mode){spr->SetMode(mode);};
	void setFrame(int n){spr->SetFrame(n);};
	void setFrames(int n){spr->SetFrames(n);};
	void setAnimeSpeed(float fps){spr->SetSpeed(fps);};

public:
	 float x, y;//該角色的座標點
	 float w, h;//圖片的長、寬
	 float targetX, targetY;
	 float rot, hscale, vscale;
	 AIEngine* ai;
	

protected:
	bool alive;
	int nframe;
	float fps;
	float velocityX, velocityY;//該Sprite的速度
	hgeAnimation*      spr;
	float theta;
	HitPoint* hitPoint;
	HGE* hge;

public:
	void runUp();
	void runDown();
	void runLeft();
	void runRight();
	int getDirection();
	static enum Direction{ //角色的方向
	   UP = 0,
	   DOWN = 1,
	   LEFT = 2,
	   RIGHT = 3
	 }; 
private:
	bool Direction[4];

};











#endif




















