#include   <stdio.h>
#include <stdlib.h>
#ifndef DEP_GAMEVARIABLE
#define DEP_GAMEVARIABLE

class GameVariable{
private:
	GameVariable();
	~GameVariable();
public://�C���ާ@�ܼ�
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

private://�C���ܼ�
	
    int score;//�ثe������
    int hiScore;//�ثe�̰����A�|�qsave.dat��Ū�i��
	bool bextra;//extra�O�_���}��
	int cont;//�C������



};

#endif