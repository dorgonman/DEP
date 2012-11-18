#include "StageResource.h"
#include "GlobalVariable.h"
#include "depGUI.h"
StageResource* StageResource::instance = NULL;


//map的三種用法  
//1.mapStudent.insert(map<int, string>::value_type (1, “student_one”));
//2.mapStudent.insert(pair<int, string>(1, “student_one”));
//3.mapStudent[1] =  “student_one”;

StageResource::StageResource(){
	playerLoad();
	enemyLoad();
	GUISetting();
	particleLoad();
}

StageResource::~StageResource(){

}


void StageResource::particleLoad(){
	float particleBase = 32.0f;
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle1.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 0, particleBase * 0, particleBase * 1, particleBase * 1)));//0, 0, 32, 32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle2.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle3.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle4.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle5.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle6.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle7.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle8.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32
	pars.push_back(new hgeParticleSystem(".\\ParticleSystem\\particle9.psi", new hgeSprite(g_rm->GetTexture(".\\ParticleSystem\\particles.png"), particleBase * 1, particleBase * 0, particleBase * 2, particleBase * 1)));//32, 0, 64,32




	vector<hgeParticleSystem*>::iterator it;
	for(it = pars.begin(); it != pars.end();it++){
		hgeParticleSystem* par = *it;
		par->info.nEmission = 300;
		par->Fire();
	}



}

void StageResource::GUISetting(){
	gui = new hgeGUI();
	gui->SetCursor(new hgeSprite(g_rm->GetTexture(".\\Picture\\cursor.png"), 0, 0, 32, 32));
	
	gui->AddCtrl(new hgeGUIMenuItem(CONTINUE, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav",0, 0,0.0f, L"Continue")); 
    gui->AddCtrl(new hgeGUIMenuItem(GIVEUP, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav",  0, 30,0.0f,L"GiveUp"));
	gui->AddCtrl(new hgeGUIMenuItem(YES, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav",     0, 0, 0.0f, L"YES"));
	gui->AddCtrl(new hgeGUIMenuItem(NO, GlobalVariable::getInstance()->getTTF(), ".\\sounds\\menu.wav",      0, 30, 0.0f, L"NO"));
	int i;
	for(i = 1; i < 4; i++){
 	  gui->EnableCtrl(i, false);
	  gui->ShowCtrl(i, false);
	}
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->Enter();
	gui->Move(100, 100);

}





void StageResource::addItem(RoleSprite* roleSpr, int amount){
	int i;
	for(i = 0; i < amount; i++){
		roleSpr->addItem(new Item(g_rm->GetTexture(".\\Picture\\job\\PointItem.png"), 0, 0, 45, 45));
	}
}


void StageResource::enemyLoad(){
	vector<RoleSprite*> roleSprs;
	int i;
	for(i = 0; i < 20; i++){
		RoleSprite* roleSpr = new EnemySprite(g_rm->GetTexture(".\\Picture\\character\\tama1.png"), 0, 0, 45, 55);
		roleSpr->setAlive(false);
		roleSpr->SetHotSpot();
		GUN* gun = new ThetaGUN(NULL, 0, 0, 0, 0);
		gun->setAlive(false);
		gun->SetHotSpot();
		gun->addBullet(GUN::PicDirect, 30, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
		roleSpr->addGUN(gun);
		addItem(roleSpr, 3);
		roleSprs.push_back(roleSpr);
	}
	mapSpr[1] = roleSprs;

}

void StageResource::playerLoad(){
	vector<RoleSprite*> roleSprs;
	RoleSprite* roleSpr = new RoleSprite(g_rm->GetTexture(".\\Picture\\character\\yumemiSD.png"), 0, 0, 45, 45);
	roleSpr->setAlive(true);
	roleSpr->setVelocity(10, 10);
	roleSpr->SetHotSpot();

	GUN* gun = new ThetaGUN(NULL, 0, 0, 0, 0);
	gun->setAlive(false);
	gun->addBullet(0, 100, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
	roleSpr->addGUN(gun);

	gun = new ThetaGUN(NULL, 0, 0, 0, 0);
	gun->setAlive(false);
	gun->addBullet(gun->NotPicDirect, 100, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
	roleSpr->addGUN(gun);

	gun = new ThetaGUN(NULL, 0, 0, 0, 0);
	gun->setAlive(false);
	gun->addBullet(0, 100, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
	roleSpr->addGUN(gun);

	 gun = new ThetaGUN(NULL, 0, 0, 0, 0);
	gun->setAlive(false);
	gun->addBullet(0, 100, g_rm->GetTexture(".\\Picture\\job\\bullet12.png"), 0, 0, 45, 45);
	roleSpr->addGUN(gun);
	addItem(roleSpr, 50);
	roleSprs.push_back(roleSpr);
	mapSpr[0] = roleSprs;


}

StageResource* StageResource::getInstance(){
	if(instance == NULL){
		instance = new StageResource();
	}
	return instance;  
}



