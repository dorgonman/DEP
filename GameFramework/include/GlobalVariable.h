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


//�o�̪���T�O�t�d�s�xinfor�檺data�����AbattleMode�|�t�d�N��render�X��
class GlobalVariable{

	private:
	    static GlobalVariable* instance;
	
	private:
		bool bstop;//�C���O�_�B��Ȱ������A
		int id;
	private://hgeFont�u�䴩�^���²�檺�\��TTF(true type font)�h�䴩��h�F��
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