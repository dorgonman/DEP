#include "Stage.h"
#include "DepControl.h"
void StageExtra::initialize(){

}


//�i�H�ۦ���j���Ӥ�����item����]�G�ѩ�C��stage���O�ۤv��guns[]�A�����u�O�qstageResource�̧�default��guns[]���L�ӦӤw
//�]���A�C��stage�ۦ�new�sgun���ܨä��|�v�T���L���d��gun(enemySprs�]�O�@�˪��D�z) ���d����vector���P ���̭������Щҫ��쪺����~�@��
//(�e50�ӬO���ЧQ��)
//�ۤϪ��A���M�C�����d���O��enemySprs[]�A����ҫ��V��item�O�P�@�ӡA�]�����������|���ۼv�T�C
void StageExtra::enemyLoad(){


}




//�`�N�A��b�]�wsprite���ɭԡA�������]�walive�A�]�w��L��T�A���M���ܡA���Ǹ�T�|�Q���]�^�w�]��(�C����setAlive�@���A�N�|�N�@�Ǹ�T�]�^�w�]��)
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