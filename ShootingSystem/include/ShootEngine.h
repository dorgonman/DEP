#include "GUN.h"
#include "RoleSprite.h"
#include "hge.h"
#include "ItemEngine.h"
#include <vector>
#include "DEPSound.h"

using namespace std;
#ifndef DEP_SHOOTENGINE
#define DEP_SHOOTENGINE

class ShootEngine{

public:
	ShootEngine();
	~ShootEngine();

private:
	HGE* hge;
	DEPSound* bulletHitSe;
    DEPSound* roleDieSe;
    DEPSound* gunTriggerSe;
public:
static enum SoundEffectMode{
		TRIGGER = 0,
		HIT = 1,
		DIE = 2
	}seMode;
	void setSoundEffect(int mode, string fileName, float volume = 100, float pan = 0, float pitch = 1.0f);

public://action
	//trigger vector內的所有的gun
	void trigger(vector<RoleSprite*>   roleSprs);
	void trigger(RoleSprite*   roleSpr);
	void trigger(vector<GUN*>   guns);
	void trigger(GUN* gun);

	void hit(vector<RoleSprite*> sourceSprs, vector<RoleSprite*> targetSprs);
	void hit(vector<RoleSprite*> sourceSprs, RoleSprite* targetSpr);
	void hit(RoleSprite* sourceSpr, vector<RoleSprite*> targetSprs);
	void hit(RoleSprite* sourceSpr, RoleSprite* targetSpr);
	void hit(vector<GUN*>   guns, RoleSprite* targetSpr);
	void hit(GUN*  gun, RoleSprite* targetSpr);


public://behavior
	static void trace(vector<RoleSprite*> sourceSprs, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void trace(vector<RoleSprite*> sourceSprs, RoleSprite* targetSpr, float radius = 1000);
	static void trace(RoleSprite* sourceSpr, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void trace(RoleSprite* sourceSpr, RoleSprite* targetSpr, float radius = 1000);
	static void trace(vector<GUN*> guns, RoleSprite* targetSpr, float radius = 1000);
	static void trace(GUN* gun, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void trace(GUN* gun, RoleSprite* targetSpr, float radius = 1000);

	//讓gun鎖定半徑範圍內還活著的角色
	static void lockon(vector<RoleSprite*> sourceSprs, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void lockon(vector<RoleSprite*> sourceSprs, RoleSprite* targetSpr, float radius = 1000);
	static void lockon(RoleSprite* sourceSpr, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void lockon(RoleSprite* sourceSpr, RoleSprite* targetSpr, float radius = 1000);
	static void lockon(vector<GUN*> guns, RoleSprite* targetSpr, float radius = 1000);
	static void lockon(GUN* gun, vector<RoleSprite*> targetSprs, float radius = 1000);
	static void lockon(GUN* gun, RoleSprite* targetSpr, float radius = 1000);



	//將gun所有的子彈方向轉向目的地
	static void setAllBulletDestination(GUN *gun, float destX, float destY);
	//取得二點之間夾角的theta值
	static float getTheta(float originX, float originY, float destX, float destY);
	static void setAllBulletTheta(GUN* gun, float theta);
	
	static void update(vector<RoleSprite*>  roleSprs);
	static void update(RoleSprite* roleSpr);
	static void update(vector<GUN*>  guns);
	static void update(GUN*  gun);

	static void render(vector<RoleSprite*>  roleSprs);
	static void render(RoleSprite* roleSpr);
	static void render(vector<GUN*>  guns);
	static void render(GUN*  gun);

};



#endif