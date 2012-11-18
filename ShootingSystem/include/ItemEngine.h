#include <vector>
#include "Item.h"
#include "RoleSprite.h"
#include "hge.h"
#include "AIEngine.h"
#include "GameVariable.h"
#include "DEPSound.h"

using namespace std;


#ifndef DEP_ITEMENGINE
#define DEP_ITEMENGINE

class ItemEngine{
public:
	ItemEngine();
	~ItemEngine();
	void setSoundEffect(int mode, string fileName, float volume = 100, float pan = 0, float pitch = 1.0f);
	static enum SoundEffectMode{
		GET = 0
	}seMode;
public:

	void check(vector<RoleSprite*> sourceSprs, vector<RoleSprite*> targetSprs);
	void check(vector<RoleSprite*> sourceSprs, RoleSprite* targetSpr);
	void check(RoleSprite* sourceSpr, vector<RoleSprite*> targetSprs);
	void check(RoleSprite* sourceSpr, RoleSprite* targetSpr);
	void check(vector<Item*> items, RoleSprite* targetSpr);
	void check(Item* item, RoleSprite* targetSpr);

	static void trigger(vector<RoleSprite*> roleSprs);
	static void trigger(RoleSprite* roleSpr);
	static void trigger(vector<Item*> items, float x, float y);
	static void trigger(Item* item, float x, float y);

	static void render(vector<RoleSprite*> roleSprs);
	static void render(RoleSprite* roleSpr);
	static void render(vector<Item*> items);
	static void render(Item* item);

	static void update(vector<RoleSprite*> roleSprs);
	static void update(RoleSprite* roleSpr);
	static void update(vector<Item*> items);
	static void update(Item* item);

	static void runToTarget(vector<RoleSprite*> roleSprs);
	static void runToTarget(RoleSprite* roleSpr);
	static void runToTarget(vector<Item*>  items);
	static void runToTarget(Item*  item);
	static void randomSearch(vector<Item*> items);


private:
	HGE* hge;
	DEPSound* itemGetSe;
public:
};



#endif