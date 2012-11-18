#include "DEPSprite.h"


#ifndef DEP_Bullet
#define DEP_Bullet

//============================Bullet==========================
class RoleSprite;

class Bullet : public DEPSprite{
	
public:
	Bullet(HTEXTURE tex, float x, float y, float w, float h) : DEPSprite(tex,  x, y,  w, h){
		initialize();
	};
	 ~Bullet(){};

	virtual void setDirection(float _theta){theta = _theta;};

	void setLethality(float _lethality){
		lethality = _lethality;
	};

	float getLethality(){return lethality;};
	void setFlyTime(float _t){t = _t;};


public:
	virtual void hit(RoleSprite* spr);
	virtual void run();
	void setAlive(bool _alive);
private:
	void initialize();


protected:
	float dt;//�g�X�h���l�u�ثe���F�X��
	float t;
	bool Direct[4];
	float px, py;//�i�歸����|�t��k�һ�
	float rotation;
	float lethality;
};





class ThetaBullet:public Bullet{
	public:
		ThetaBullet(HTEXTURE tex, float x, float y, float w, float h) : Bullet(tex,  x, y,  w, h){
		};

		virtual void run();
		void setDirection(float _theta);

};



class PicDirectBullet:public ThetaBullet{
public:
	PicDirectBullet(HTEXTURE tex, float x, float y, float w, float h) : ThetaBullet(tex,  x, y,  w, h){};
	virtual void run();
};



class PenetratePicDirectBullet:public PicDirectBullet{
public:
	PenetratePicDirectBullet(HTEXTURE tex, float x, float y, float w, float h) :PicDirectBullet(tex,  x, y,  w, h){};
	virtual void hit(RoleSprite* spr);

};
class NotPicDirectBullet:public ThetaBullet{
public:
	NotPicDirectBullet(HTEXTURE tex, float x, float y, float w, float h) : ThetaBullet(tex,  x, y,  w, h){
		RT = 0;
		dRT = 10;
	};
	virtual void run();
	void setAutoRotation(float _rt){dRT = _rt;};
private:
	float RT;//picRotationTheta;
	float dRT;

};


class BounceNotPicBullet:public NotPicDirectBullet{
public:
	BounceNotPicBullet(HTEXTURE tex, float x, float y, float w, float h) : NotPicDirectBullet(tex,  x, y,  w, h){}
	void run();
};




class CircleBullet : public Bullet{
public:
	CircleBullet(HTEXTURE tex, float x, float y, float w, float h) : Bullet(tex,  x, y,  w, h){
	
			t = 2;
			theta = 10.0f;
			rotation = 1;//�[�t�� 
		};
	void run();

};





class WaveBullet:public Bullet{
	public:
		WaveBullet(HTEXTURE tex, float x, float y, float w, float h) : Bullet(tex,  x, y,  w, h){
			startTheta = 10.0f;
			endTheta = 180.0f;
			interval = 2;
		};
		void run();
	private:
		float startTheta;// start����
		float endTheta;//end
		float interval;//�ܤƨ��װ϶�����


};


//===================================================

#endif