#include "Stage.h"
#include "DepControl.h"
void StageExtra::initialize(){

}


//可以自行更改槍隻而不能更改item的原因：由於每個stage都保自己的guns[]，初期其只是從stageResource裡把default的guns[]拿過來而已
//因此，每個stage自行new新gun的話並不會影響到其他關卡的gun(enemySprs也是一樣的道理) 關卡中的vector不同 但裡面的指標所指到的物件才一樣
//(前50個是重覆利用)
//相反的，雖然每個關卡都保有enemySprs[]，但其所指向的item是同一個，因此彼此之間會互相影響。
void StageExtra::enemyLoad(){


}




//注意，當在設定sprite的時候，必須先設定alive再設定其他資訊，不然的話，有些資訊會被重設回預設值(每執行setAlive一次，就會將一些資訊設回預設值)
void StageExtra::doLoadingScript(){
	scriptMode = BATTLE;
}



void StageExtra::doBattleScript(){
	StageControl::doBattleScript();

	

}


void StageExtra::doStoryScript(){


}


void StageExtra::doFinishScript(){
	DepControl::getInstance()->selectGame(3);
}


void StageExtra::doScreenScript(){
	StageControl::doScreenScript();
}