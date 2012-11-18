#include "GlobalVariable.h"
#include <string.h>//字串操作相關需要 
#include <vector>
#include "DepControl.h"

using namespace std;
GlobalVariable* GlobalVariable::instance = NULL;



GlobalVariable* GlobalVariable::getInstance(){
	if(instance == NULL){
		instance = new GlobalVariable();
		//instance->fnt->printf(200,200,0, "create");
	}
	return instance;
}


GlobalVariable::~GlobalVariable(){
	delete engFnt;
	g_hge->Release();
	delete font;
}

 GlobalVariable::GlobalVariable(){
		fontInit();
}



void GlobalVariable::fontInit(){

		g_hge->System_Log("遊戲使用了字體ARIALUNI.TTF(Arial Unicode MS)");
		engFnt = new hgeFont("font1.fnt");
		FontMgr = new FontManager();
		FontMgr->Initialize();
	
		FontMgr->loadFont("ARIALUNI.TTF");
		font = FontMgr->getFont("ARIALUNI.TTF");

		if(font != NULL){
			font->setSize(32);
			font->cacheChars('a', 'z');
			font->cacheChars(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		}
		

}






Font* GlobalVariable::getTTF(){
	return font;
}