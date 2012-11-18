#include "RoleSprite.h"
#include <vector>
#include "ItemEngine.h"
#include "ShootEngine.h"
using namespace std;

#ifndef DEP_ROLEENGINE
#define DEP_ROLEENGINE

class RoleEngine{
public:
	static void render(vector<RoleSprite*> roleSprs);
	static void render(RoleSprite* roleSpr);
	static void update(vector<RoleSprite*> roleSprs);
	static void update(RoleSprite* roleSpr);
};





#endif