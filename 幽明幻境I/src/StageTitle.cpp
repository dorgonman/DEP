#include "Stage.h"
#include "DepControl.h"
#include "depGUI.h"
static hgeGUI* titleGUI;

void StageTitle::initialize(){
	titleGUI = new hgeGUI();
	titleGUI->AddCtrl(new hgeGUIMenuItem(1, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav", 0, 0,0.0f,     L"New Game")); 
	titleGUI->AddCtrl(new hgeGUIMenuItem(2, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav", 0, 40,0.0f,  L"Extra")); 
    titleGUI->AddCtrl(new hgeGUIMenuItem(3, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav",  0, 80,0.0f,  L"Exit"));
	titleGUI->SetCursor(new hgeSprite(g_rm->GetTexture(".\\Picture\\cursor.png"), 0, 0, 32, 32));
	titleGUI->Move(670, 400);
	titleGUI->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	titleGUI->Enter();
	
}




void StageTitle::doLoadingScript(){
	depControl->getVideoManager()->playFile(L"test.avi");
	//bgSpr->SetTexture(rm->GetTexture(".\\Picture\\job\\titile_pic.png"));
	bgSpr->SetTextureRect(0, 0, 800, 600);
	DepControl::getInstance()->setGameMode(MAINLOOP);
	scriptMode = STORY;

}

//�B�z�v����script~
void StageTitle::doStoryScript(){
	if(g_hge->Input_KeyDown(HGEK_ESCAPE)){
		depControl->getVideoManager()->stop();
	}
}




//��v���b����ɡA��Script�|�Ȱ�����
void StageTitle::doScreenScript(){
		StageControl::doScreenScript();
		int titleID;
		bgSpr->Render(0, 0);
		GlobalVariable::getInstance()->getTTF()->setSize(25);
		titleID = titleGUI->Update(g_hge->Timer_GetDelta());
		titleGUI->Render();
		


		switch(titleID){
			case 1:
				doFinishScript();
				DepControl::getInstance()->selectGame(1);
				GameVariable::getInstance()->setCont(4);
				titleID = 0;	
			break;
			case 2:		
				doFinishScript();
				DepControl::getInstance()->selectGame(2);
				GameVariable::getInstance()->setCont(1);
				titleID = 0;
				break;
			case 3:
				doFinishScript();
				DepControl::getInstance()->setExit(true);
				id = 0;
			break;
		}


}

//���`�{���y�{��F���F�A�]���@selectGame����Acontrol�ұ�����d�N���W���ܤF
//���D�NselectGame�����FinishScript�̰���Ϊ̬O�bdoScreenScript�̪����I�s
void StageTitle::doFinishScript(){
		DepControl::getInstance()->resetGame();
		GameVariable::getInstance()->setScore(0);
}