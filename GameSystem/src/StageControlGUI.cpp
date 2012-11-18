#include "StageControl.h"
#include "DepControl.h"
#include "GameVariable.h"
void StageControl::BattleGUIFunction(){
	static float delay = 0;

	if(playerSpr->isAlive()){
 		  gui->EnableCtrl(1, true);
		  gui->ShowCtrl(1, true);
		  gui->EnableCtrl(2, true);
		  gui->ShowCtrl(2, true);
		  gui->EnableCtrl(3, false);
		  gui->ShowCtrl(3, false);
		  gui->EnableCtrl(4, false);
		  gui->ShowCtrl(4, false);
		if(g_hge->Input_KeyDown(HGEK_ESCAPE)){		
			GlobalVariable::getInstance()->setStop(!GlobalVariable::getInstance()->isStop());
		}
	}else{
		if(!GlobalVariable::getInstance()->isStop()){
			if(delay == 0){
				itemSe->trigger(playerSpr);
			}
			delay += g_hge->Timer_GetDelta();
		}

		if(delay >=1){
			GlobalVariable::getInstance()->setStop(true);
			delay = 0;
		}
			
		  gui->EnableCtrl(1, false);
		  gui->ShowCtrl(1, false);
		  gui->EnableCtrl(2, false);
		  gui->ShowCtrl(2, false);
		  gui->EnableCtrl(3, true);
		  gui->ShowCtrl(3, true);
		  gui->EnableCtrl(4, true);
		  gui->ShowCtrl(4, true);

	}


	Font* font = GlobalVariable::getInstance()->getTTF();
	font->setColor(0xFFFFFFFF);
	font->setSize(35);

	if(GlobalVariable::getInstance()->isStop()){
		if(GameVariable::getInstance()->getCont() > 0){	
			gui->Render();
			id = gui->Update(g_hge->Timer_GetDelta());
			if(playerSpr->isAlive()){
				font->printf(280, 200,  L"暫停模式");
			}else{
				font->printf(280, 200,  L"是否接關？\n您還剩餘%d次", GameVariable::getInstance()->getCont());
			}
		}else{
			id = res->NO;
		}

	}else{
		gui->SetFocus(0);
	}

		vector<Item*> items = playerSpr->getItems();
		vector<Item*>::iterator items_it;
		switch(id){
		case res->CONTINUE://continue
			id = 0;
			GlobalVariable::getInstance()->setStop(false);	
			break;
		case res->GIVEUP://GIVEUP
			doFinishScript();
			DepControl::getInstance()->selectGame(0);//回title
			g_hge->Channel_StopAll();
			id = 0;//將選擇的初始化
			GlobalVariable::getInstance()->setStop(false);
			break;
		case res->YES://YES
			id = 0;
			this->resetPlayer();
			for( items_it = items.begin(); items_it != items.end(); items_it++ ){
				Item* item = *items_it;
				item->setAlive(true);
			}
			GameVariable::getInstance()->setCont(GameVariable::getInstance()->getCont() - 1);
			GlobalVariable::getInstance()->setStop(false);	
			break;
		case res->NO://NO
			doFinishScript();
			DepControl::getInstance()->selectGame(0);//回title
			g_hge->Channel_StopAll();
			id = 0;//將選擇的初始化
			GlobalVariable::getInstance()->setStop(false);	
			break;
	}

}


