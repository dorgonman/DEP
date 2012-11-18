#include "DEPSprite.h"

void DEPSprite::setAI(AIEngine* _ai){
	ai = _ai;
}
AIEngine* DEPSprite::getAI(){
	return ai;
}


void DEPSprite::RenderEx(){
	spr->RenderEx(x, y, rot, hscale, vscale);
}

DEPSprite::DEPSprite(HTEXTURE _tex, float _x, float _y, float _w, float _h, int frame, float fps){
		hge = hgeCreate(HGE_VERSION);
		if(_tex == NULL){
			_tex = g_rm->GetTexture("defaultPic.png");
			_x = 0; _y = 0;
			_w = 45; _h = 45;
		}

		spr = new hgeAnimation(_tex, frame, fps, _x, _y, _w, _h);
		spr->Play();
		
		x = 0; y = 0;
		targetX = x; targetY = y;
		w = _w;
		h = _h;
		rot = 0;
		hscale = 1;
		vscale = 1;
		setVelocity(3);
		theta = 0;	
		setAlive(false);
		hitPoint = new HitPoint(this->GetBoundingBox(), 5);

	//初始方向為右邊
		Direction[0] = false;
		Direction[1] = false;
		Direction[2] = false;
		Direction[3] = true;
		ai = new AIEngine();
}

DEPSprite::~DEPSprite(){

		hge->Release();
		if(spr)  delete spr;
		if(ai) delete ai;
		if(hitPoint) delete hitPoint;
		spr = NULL;
		ai = NULL;
		hitPoint = NULL;
}




void DEPSprite::update(){
		hitPoint->update(x, y, w, h);
		spr->Update(hge->Timer_GetDelta());
}




void DEPSprite::setPosition(float _x, float _y){
	 this->x = _x;
	 this->y = _y;
	 this->targetX = x;
	 this->targetY = y;
}

void DEPSprite::SetTexture(HTEXTURE _tex){
	if(_tex == NULL){
		_tex = g_rm->GetTexture("defaultPic.png");
		w = 45; h = 45;
	}
	spr->SetTexture(_tex);
}

void DEPSprite::SetTextureRect(float x, float y, float w, float h, bool adjSize){
	 spr->SetTextureRect(x, y, w, h);
}

void DEPSprite::setAlive(bool _alive){
	alive = _alive;
}


void DEPSprite::setVelocity(float _velocityX, float _velocityY ){
	this->velocityX = _velocityX;
	this->velocityY = _velocityY;

}



#include <iostream>
#include <io.h>
#include <fcntl.h>

void redirectIOToConsole(){
    // Allocate a console so we can output some useful information.
    AllocConsole();

    // Get the handle for STDOUT's file system.
    HANDLE stdOutputHandle = GetStdHandle( STD_OUTPUT_HANDLE );

    // Redirect STDOUT to the new console by associating STDOUT's file 
    // descriptor with an existing operating-system file handle.
    int hConsoleHandle = _open_osfhandle( (intptr_t)stdOutputHandle, _O_TEXT );
    FILE *pFile = _fdopen( hConsoleHandle, "w" );
    *stdout = *pFile;
    setvbuf( stdout, NULL, _IONBF, 0 );

    // This call ensures that iostream and C run-time library operations occur  
    // in the order that they appear in source code.
    ios::sync_with_stdio();
}

