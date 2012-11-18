#include "..\include\DEPSprite.h"






int DEPSprite::getDirection(){
	if(Direction[0]){
		return DEPSprite::UP;
	}
	if(Direction[1]){
		return DEPSprite::DOWN;
	}
	if(Direction[2]){
		return DEPSprite::LEFT;
	}
	if(Direction[3]){
		return DEPSprite::RIGHT;
	}
	return DEPSprite::UP;
}





void DEPSprite::runUp(){
	y -= velocityY;
	Direction[0] =true;
	Direction[1] =false;
	Direction[2] =false;
	Direction[3] =false;
}

void DEPSprite::runDown(){

	y += velocityY;
	Direction[0] =false;
	Direction[1] =true;
	Direction[2] =false;
	Direction[3] =false;
}


void DEPSprite::runLeft(){
	x -= velocityX;
	Direction[0] =false;
	Direction[1] =false;
	Direction[2] =true;
	Direction[3] =false;

	

}


void DEPSprite::runRight(){

	x += velocityX;

	Direction[0] =false;
	Direction[1] =false;
	Direction[2] =false;
	Direction[3] =true;
}

