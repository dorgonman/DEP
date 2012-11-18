#pragma once
#include   <stdio.h>
#include   "hgeFont.h"
#include    "hge.h"
#include <stdlib.h>
#include "FontManager.h"
#include "Font.h"

using namespace hgeTTF;

#ifndef DEP_GlobalVariable
#define DEP_GlobalVariable

static HGE*   g_hge = hgeCreate(HGE_VERSION);


//這裡的資訊是負責存儲infor欄的data部份，battleMode會負責將其render出來
class GlobalVariable{

	private:
	    static GlobalVariable* instance;
	
	private:
		bool bstop;//遊戲是否處於暫停的狀態
		int id;
	private://hgeFont只支援英文及簡單的功能TTF(true type font)則支援更多東西
		hgeFont*	engFnt;
		FontManager* FontMgr;
		Font* font;
	protected:
		GlobalVariable();
		~GlobalVariable();
		void fontInit();
	public:
		static GlobalVariable* getInstance();
		hgeFont* getFont(){return engFnt;};
		Font* getTTF();
		FontManager* getTTFMgr(){return FontMgr;};
		bool isStop(){return bstop;}
		void setStop(bool _b){bstop = _b;};
		
};

#endif