#include "Item.h"


#ifndef DEP_STAGEITEM
#define DEP_STAGEITEM

class SmallHPItem:public Item{
public:

	SmallHPItem(HTEXTURE tex, float x, float y, float w, float h) : Item(tex, x, y, w, h){
		 spr->SetTexture(g_rm->GetTexture(".\\Picture\\job\\HPItem.png"));
		 setSize(0.3f, 0.3f);
		 score = 30;
	  };
	  void execute(RoleSprite* role);
};

class BigHPItem:public Item{
public:
	BigHPItem(HTEXTURE tex, float x, float y, float w, float h) : Item(tex, x, y, w, h){
		 spr->SetTexture(g_rm->GetTexture(".\\Picture\\job\\HPItem.png"));
		 score = 50;
	  };
	  void execute(RoleSprite* role);
};





class PanaceaItem:public Item{
public:
	PanaceaItem(HTEXTURE tex, float x, float y, float w, float h) : Item(tex, x, y, w, h){
		 spr->SetTexture(g_rm->GetTexture(".\\Picture\\job\\SItem.png"));
		  score = 200;
	  };
	 void execute(RoleSprite* role);
};

#endif