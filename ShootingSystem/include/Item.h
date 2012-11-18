#include "DEPSprite.h"

#ifndef DEP_ITEM
#define DEP_ITEM

class RoleSprite;


class Item:public DEPSprite{
public:

	Item(HTEXTURE tex, float x, float y, float w, float h) : DEPSprite(tex, x, y ,w, h){
		  initialize();
	  };
	  void update();

	  void setScore(int _s){score = _s;};
	  int getScore(){return score;};

public:
      virtual void execute(RoleSprite* role);
	  virtual void setAlive(bool _alive);
	  float getMT(){return mt;};
	  void setMT(float _mt){mt = _mt;};
	  float getDT(){return dt;};
	  void setDT(float _dt){dt = _dt;};

private:
	void initialize();
protected:
	int score;
private:
	float mt;//item可存在的時間
	float dt;//item存在的經過時間
};




#endif