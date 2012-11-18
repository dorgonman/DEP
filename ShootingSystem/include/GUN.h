#include "DEPSprite.h"
#include "Bullet.h"
#include <vector>
using namespace std; 
#ifndef DEP_GUN
#define DEP_GUN

//==========================GUN===================================

class GUN : public DEPSprite{
public:
	//GUN(HTEXTURE tex);//設定這把槍的圖片
	GUN(HTEXTURE tex, float x, float y, float w, float h);
	~GUN();
public:
	virtual void trigger();
	virtual void update();
	virtual void RenderEx();
public:
	virtual void setBulletDestination(float dx , float dy);
	void setBullet(int i,Bullet* newbullet);
	Bullet* getBullet(int i){return bulletSprs[i];};
	vector<Bullet*> getBulletSprs(){return bulletSprs;};
	void setBulletVelocity(float velocityX, float velocityY = 3);
	int  getBulletAmount(){return (int)bulletSprs.size();};
	void setBulletSize(float hscale,float vscale);
	void setAlive(bool _alive);
	void setBulletAphabate(DWORD a);
	void setBulletColor(DWORD col);
	void setLethality(float lethality);
	float getShootingTime(){return sit;};
	void  setShootingTime(float _sit){sit = _sit;};
	float getDSIT(){return dsit;};
	void setDSIT(float d){dsit = d;};
	int  getPattern(){return pattern;};
	void setPattern(int i){pattern = i;};
	float getShootTheta(){return shootTheta;};
	void setBulletFlyTime(float ft);
	void setBulletHitRadius(float r);
	void setBulletTexture(HTEXTURE tex);
	void setBulletTextureRect(float x, float y, float w, float h);
	void addBullet(int type, int amount, HTEXTURE tex = NULL, float x = 0, float y = 0, float w = 0, float h = 0);

	static enum bullet_type{
		PicDirect = 0,
		NotPicDirect = 1,
		Bounce = 2,
		PenetratePic = 3
	};
private:
	void addBullet(Bullet* bullet);

protected:
	int bullet;//現在子彈的數量
	float shootTheta;
	int pattern;//現在這把手槍的子彈模式
	float sit, dsit;
	float destX;
	float destY;
	vector<Bullet*> bulletSprs;
	bool Direction[4];//依予為上、下、左、右
};



class ThetaGUN : public GUN{
public:
	ThetaGUN(HTEXTURE tex, float x, float y, float w, float h);
	virtual void trigger();

protected:
	void pattern0();
	void pattern1();//nway
	void pattern2();

};

class IncreGUN : public ThetaGUN{
public:
	IncreGUN(HTEXTURE tex, float x, float y, float w, float h);
	virtual void update();


protected:
	void pattern0();
	void pattern1();//nway
	void pattern2();

};






//==========================================================



#endif