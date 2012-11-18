#include "GUN.h"

void GUN::addBullet(int type, int amount, HTEXTURE tex, float x, float y, float w, float h){
	
	
	int i;
	for(i = 0; i < amount; i++){
		Bullet* bullet;
		switch(type){
			case PicDirect:
				bullet = new PicDirectBullet(tex, x, y, w ,h);
				addBullet(bullet);
				break;
			case NotPicDirect:
				bullet = new NotPicDirectBullet(tex, x, y, w ,h);
				addBullet(bullet);
				break;
			case Bounce:
				bullet = new BounceNotPicBullet(tex, x, y, w ,h);
				addBullet(bullet);
				break;
			case PenetratePic:
				bullet = new PenetratePicDirectBullet(tex, x, y, w ,h);
				addBullet(bullet);
				break;
		}
	}

}

void GUN::addBullet(Bullet *bullet){
	bulletSprs.push_back(bullet);
}


void GUN::setLethality(float lethality){


	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->setLethality(lethality);
	}



}


void GUN::setBulletDestination(float dx, float dy){
	destX = dx;
	destY = dy;
}



void GUN::setBulletVelocity(float velocityX, float velocityY){

	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet = *it;
		bullet->setVelocity(velocityX, velocityY);
	}


}


void GUN::setBullet(int i, Bullet* newBullet){
     bulletSprs[i] = newBullet;

}


void GUN::setBulletAphabate(DWORD a){
	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->setAphabate(a);
	}
}



void GUN::setBulletFlyTime(float FT){


	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->setFlyTime(FT);
	}

}

void GUN::setBulletHitRadius(float r){

	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->getHitPoint()->setHitRadius(r);
	}

}

void GUN::setBulletTexture(HTEXTURE tex){


	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->SetTexture(tex);
	}


}


void GUN::setBulletSize(float hscale, float vscale){

	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->setSize(hscale, vscale);
	}


}

void GUN::setBulletTextureRect(float x, float y, float w, float h){


	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->SetTextureRect(x, y, w, h);
	}



}



void GUN::setBulletColor(DWORD col){

	vector<Bullet*>::iterator it;
	for( it = bulletSprs.begin(); it != bulletSprs.end(); it++ ){
		Bullet* bullet= *it;
		bullet->setColor(col);
	}


}


