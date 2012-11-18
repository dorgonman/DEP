#include "ItemEngine.h"

ItemEngine::ItemEngine(){
	hge = hgeCreate(HGE_VERSION);
	itemGetSe = new DEPSound();

}
ItemEngine::~ItemEngine(){
	hge->Release();
}


void ItemEngine::setSoundEffect(int mode, string fileName, float volume, float pan, float pitch){

	if(mode == GET){
		itemGetSe->setSoundEffect(fileName, volume, pan, pitch);
	}
}







