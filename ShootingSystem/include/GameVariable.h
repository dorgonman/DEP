#include   <stdio.h>
#include <stdlib.h>
#ifndef DEP_GAMEVARIABLE
#define DEP_GAMEVARIABLE

class GameVariable{
private:
	GameVariable();
	~GameVariable();
public://遊戲操作變數
	 void addScore(int s);
	 void setScore(int s){score = s;};
	 int getCont(){return cont;};
	 void setCont(int _cont){cont = _cont;};
	 bool getExtra(){return bextra;};
	 void setExtra(bool _b){bextra = _b;};
	 int getHiScore(){return hiScore;};
	 int getScore(){return score;};

	 void saveData();
	 void readData();
     static GameVariable* getInstance();
private:
   static GameVariable* instance;

private://遊戲變數
	
    int score;//目前的分數
    int hiScore;//目前最高分，會從save.dat檔讀進來
	bool bextra;//extra是否為開啟
	int cont;//遊戲次數



};

#endif