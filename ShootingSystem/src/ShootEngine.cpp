#include "ShootEngine.h"
#include "ItemEngine.h"


ShootEngine::ShootEngine(){
	hge = hgeCreate(HGE_VERSION);
	bulletHitSe = new DEPSound();
    roleDieSe = new DEPSound();
    gunTriggerSe = new DEPSound();
}
ShootEngine::~ShootEngine(){
	hge->Release();
}
void ShootEngine::setSoundEffect(int mode, string fileName, float volume, float pan, float pitch){

	if(mode == TRIGGER){
		gunTriggerSe->setSoundEffect(fileName, volume, pan, pitch);
	}

	if(mode == HIT){
		bulletHitSe->setSoundEffect(fileName, volume, pan, pitch);
	}

	if(mode == DIE){
		roleDieSe->setSoundEffect(fileName, volume, pan, pitch);
	}
}





