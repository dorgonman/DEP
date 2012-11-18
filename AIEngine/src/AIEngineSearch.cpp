#include "AIEngine.h"
#include "DEPSprite.h"

void AIEngine::searchTarget(DEPSprite *sourceSpr, float targetX, float targetY, float radius){
	hitPoint->update(sourceSpr->x, sourceSpr->y, 1, 1);
	hitPoint->setHitRadius(radius);
	if(hitPoint->TestPoint(targetX, targetY)){
		sourceSpr->setTargetPosition(targetX, targetY);
	}

}

void AIEngine::searchTarget(DEPSprite *sourceSpr, DEPSprite *targetSpr, float radius){
	hitPoint->update(sourceSpr->x, sourceSpr->y, sourceSpr->h, sourceSpr->w);
	hitPoint->setHitRadius(radius);
	if(hitPoint->TestPoint(targetSpr->x, targetSpr->y)){
		sourceSpr->setTargetPosition(targetSpr->x, targetSpr->y);
	}
}


void AIEngine::randomJump(DEPSprite* spr){

	if(spr->getHitPoint()->TestPoint(spr->targetX, spr->targetY)){ //�p�G��F�ت��a�A�h�M��U�@�ӥت��a
		float tmpX = hge->Random_Float(mapX, mapWidth);
		float tmpY = hge->Random_Float(mapY, mapHeight) ; 
		spr->setPosition(tmpX, tmpY);
		tmpX = hge->Random_Float(mapX, mapWidth);
		tmpY = hge->Random_Float(mapY, mapHeight) ;  
		spr->setTargetPosition(tmpX, tmpY);
	}

}


void AIEngine::randomSearch(DEPSprite* spr){
	if(spr->getHitPoint()->TestPoint(spr->targetX, spr->targetY)){ //�p�G��F�ت��a�A�h�M��U�@�ӥت��a
		float tmpX = hge->Random_Float(mapX, mapWidth);
		float tmpY = hge->Random_Float(mapY, mapHeight);
		spr->setTargetPosition(tmpX, tmpY);
	}

}


void AIEngine::randomSearch(float *_x, float *_y){
    *_x =   hge->Random_Float(mapX, mapWidth);
	*_y =  hge->Random_Float(mapY, mapHeight) ; 
}


