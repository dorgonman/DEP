#include "StageControl.h"


//�b�o���e�|����l�ƩҦ���role�Aplayer������T�n���s�]�w
void StageControl::resetPlayer(){
	playerSpr->setAlive(true);
	playerSpr->setHP(100);
	playerSpr->setHitRadius(0);

	playerSpr->getGUN(0)->setAlive(true);
	playerSpr->getGUN(0)->setShootingTime(0.1f);
	playerSpr->getGUN(0)->setBulletFlyTime(1.5f);
	playerSpr->getGUN(0)->setBulletTexture(rm->GetTexture(".\\Picture\\job\\bullet10.png"));
	playerSpr->getGUN(0)->setLethality(20);
	playerSpr->getGUN(1)->setAlive(true);
	playerSpr->getGUN(1)->setShootingTime(0.1f);
	playerSpr->getGUN(1)->setBulletFlyTime(2.5f);
	playerSpr->getGUN(1)->setBulletTexture(rm->GetTexture(".\\Picture\\job\\yumemiShootType01.png"));

	playerSpr->getGUN(2)->setAlive(true);
	playerSpr->getGUN(2)->setShootingTime(0.1f);
	playerSpr->getGUN(2)->setBulletFlyTime(20);
	playerSpr->getGUN(2)->setBulletFlyTime(7);
	playerSpr->getGUN(2)->setBulletVelocity(10);
	playerSpr->getGUN(2)->setLethality(20);
	playerSpr->getGUN(2)->setBulletTexture(rm->GetTexture(".\\Picture\\job\\butterfly.png"));


	playerSpr->getGUN(0)->setLethality(40);
	playerSpr->setSize(0.5f, 0.5f);
	playerSpr->setVelocity(7, 7);


	vector<GUN*>::iterator it;
	vector<GUN*> guns = playerSpr->getGUNS();
	for(it = guns.begin(); it != guns.end(); it++){
		GUN* gun = *it;
		gun->setBulletAphabate(0x55);
	}
	playerGUN = playerSpr->getGUN(2);



}