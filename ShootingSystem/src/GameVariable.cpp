#include "GameVariable.h"
#include <string.h>//字串操作相關需要 
#include "DEPSprite.h"
#pragma warning(disable: 4996)
GameVariable* GameVariable::instance = NULL;

GameVariable::GameVariable(){
		bextra = false;
		cont = 2;
		score = 0;
		hiScore = 0;
		readData();
		saveData();
}

GameVariable::~GameVariable(){
	g_rm->Purge();
	delete g_rm;
	delete instance;
}

GameVariable* GameVariable::getInstance(){
	if(instance == NULL){
		instance = new GameVariable();
	}
	return instance;
}



void GameVariable::readData(){
		FILE* saveData;

		fopen_s(&saveData,"save.dat", "r");
		char label[50] = "";
		if ( saveData != NULL ) {

			while(!feof(saveData)){
				fscanf(saveData, "%s", label);

				if(strcmp(label, "[score]") == 0){ 

					fscanf(saveData, "%d%s", &hiScore, label);
				}
				if(strcmp(label, "[extra]") == 0){ 

					fscanf(saveData, "%d%s", &bextra, label);
				}
			}
		
			fclose(saveData);
		}	
}


void GameVariable::saveData(){
	FILE* saveData;
	int level = 3;
	fopen_s(&saveData,"save.dat", "w");
	fprintf(saveData, "[score]\n");
	fprintf(saveData, "%d\n", hiScore);
	fprintf(saveData, "[/score]\n");
	fprintf(saveData, "[extra]\n");
	fprintf(saveData, "%d\n", bextra);
	fprintf(saveData, "[/extra]\n");
	fclose(saveData);
}



void GameVariable::addScore(int s){

	score = score + s;
	if(score > hiScore){
		hiScore = score;
	}
}