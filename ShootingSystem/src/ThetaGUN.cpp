#include "GUN.h"
#include    "math.h"


ThetaGUN::ThetaGUN(HTEXTURE tex, float x, float y, float w, float h) : GUN(tex, x, y, w ,h){
		shootTheta = 1;
}

void ThetaGUN::trigger(){
	GUN::trigger();
	if((int)bulletSprs.size() == 0){	
		return;
	}

	if(pattern == 0){
		pattern0();
	}
	
	if(pattern == 1){
		pattern1();
	}

	if(pattern == 2){
		pattern2();
	}

}


void ThetaGUN::pattern0(){
	Bullet* bulletSpr;
	bulletSpr = bulletSprs[bullet];
	bulletSpr->setAlive(true);
	bulletSpr->setPosition(x, y);//쨖펥Ν┬헕
	bulletSpr->setDirection(shootTheta);
	bullet = (bullet + 1) % (int)bulletSprs.size();

}



//NWAY
void ThetaGUN::pattern1(){
	int nbullet = (int)bulletSprs.size();
	bulletSprs[bullet]->setAlive(true);
	bulletSprs[bullet]->setPosition(x, y-30);//쨖펥Ν┬헕
	
	bulletSprs[(bullet+1) % nbullet]->setAlive(true);
	bulletSprs[(bullet+1) % nbullet]->setPosition(x, y);//쨖펥Ν┬헕
	
	bulletSprs[(bullet+2) % nbullet]->setAlive(true);
	bulletSprs[(bullet+2) % nbullet]->setPosition(x, y+30);//쨖펥Ν┬헕
	
	bulletSprs[(bullet+3) % nbullet]->setAlive(true);
	bulletSprs[(bullet+3) % nbullet]->setPosition(x, y);//쨖펥Ν┬헕
	
	bulletSprs[(bullet+4) % nbullet]->setAlive(true);
	bulletSprs[(bullet+4) % nbullet]->setPosition(x, y+30);//쨖펥Ν┬헕


	shootTheta = hge->Random_Float(0,360);   //nway

	bulletSprs[bullet]->setDirection(shootTheta);
	bulletSprs[(bullet+1) % nbullet]->setDirection(float(((int)shootTheta + 30)%360));
	bulletSprs[(bullet+2) % nbullet]->setDirection(float(((int)shootTheta  + 30 * 2)%360));
	bulletSprs[(bullet+3) % nbullet]->setDirection(float(((int)shootTheta  + 30 * 3)%360));
	bulletSprs[(bullet+4) % nbullet]->setDirection(float(((int)shootTheta  + 30 * 4)%360));
	bullet = (bullet + 5) % nbullet;
}





void ThetaGUN::pattern2(){
	Bullet* bullet1;

	int i;
	if((shootTheta > 45 && shootTheta < 145) || (shootTheta > 225 && shootTheta < 145*2)){
		for(i = 0; i < 15;i++){
			bullet1 = bulletSprs[bullet];
			bullet1->setAlive(true);
			bullet1->setPosition(x + i * 10, y);//쨖펥Ν┬헕
			bullet1->setDirection(shootTheta);
			bullet = (bullet + 1) % (int)bulletSprs.size();
		}
		for(i = 0; i < 15;i++){
			bullet1 = bulletSprs[bullet];
			bullet1->setAlive(true);
			bullet1->setPosition(x - i * 10, y);//쨖펥Ν┬헕
			bullet1->setDirection(shootTheta);
			bullet = (bullet + 1) % (int)bulletSprs.size();	
		}
	}else{
		for(i = 0; i < 15;i++){
			bullet1 = bulletSprs[bullet];
			bullet1->setAlive(true);
			bullet1->setPosition(x , y+ i * 10);//쨖펥Ν┬헕
			bullet1->setDirection(shootTheta);
			bullet = (bullet + 1) % (int)bulletSprs.size();
		}
		for(i = 0; i < 15;i++){
			bullet1 = bulletSprs[bullet];
			bullet1->setAlive(true);
			bullet1->setPosition(x , y- i * 10);//쨖펥Ν┬헕
			bullet1->setDirection(shootTheta);
			bullet = (bullet + 1) % (int)bulletSprs.size();
		}
	
	
	}



}