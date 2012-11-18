#include "AIEngine.h"
#include "DEPSprite.h"

//targetSpr->x = (sourceSpr->x ) * cos(radians) - (sourceSpr->y ) * sin(radians));
//targetSpr->y =(sourceSpr->x ) * sin(radians) + (sourceSpr->y ) * cos(radians));




void AIEngine::runToTarget(DEPSprite *spr, float targetX, float targetY){
	spr->setTargetPosition(targetX, targetY);
	runToTarget(spr);
}

void AIEngine::runToTarget(vector<DEPSprite*> sprs){
		vector<DEPSprite*>::iterator it;
		for( it = sprs.begin(); it != sprs.end(); it++ ){
			DEPSprite* spr = *it;
			runToTarget(spr);
		}
}


void AIEngine::runToTarget(DEPSprite *spr){
	
			if(spr->y > spr->targetY){
				spr->runUp();
			}
			if(spr->y < spr->targetY){
				spr->runDown();
			}
			if(spr->x > spr->targetX){
				spr->runLeft();
			}
			if(spr->x < spr->targetX){
				spr->runRight();
			}

}

void AIEngine::runTo(DEPSprite* spr, float theta){
	float radians = theta * 3.14159f / 180.0f; //使用於sin & cos 函數
	spr->x +=  spr->getVelocityX()*cos(radians);
	spr->y +=  spr->getVelocityY()*sin(radians); 
}

//sourceSpr：要基於哪一個sprite的點來繞圓
//targetSpr：執行繞圓的目標sprite
//radius：要繞多大圈
//speed：繞的速度
void AIEngine::runCircle(DEPSprite *sourceSpr, DEPSprite *targetSpr, float radius, float speed, float startTheta){
	static float theta = startTheta;
	float radians = theta * 3.14159f / 180.0f; //使用於sin & cos 函數
	targetSpr->setPosition(sourceSpr->x, sourceSpr->y);//基於哪一個點來繞圓 
	targetSpr->x +=  radius*cos(radians);
	targetSpr->y +=  radius*sin(radians); 
	theta = theta + speed;//繞圓速度
	if(theta > 360){theta = 0;}

}

//用radiusAddSpeed來控制是否要有向內轉的機制
void AIEngine::runSpiral(DEPSprite *sourceSpr, DEPSprite *targetSpr, float speed, unsigned long minRadius, unsigned long maxRadius , float radiusAddSpeed){
	static float i = ((minRadius / abs(radiusAddSpeed)) * 104 ) + 104;
	static float radius = minRadius;
	//cout << i << endl;

	//system("PAUSE");

	if(abs(radius) < maxRadius){
		radius = radiusAddSpeed * ( 104 - i) / 104.0f;
		i += radiusAddSpeed;
	}
	//cout << i << "," << radius << endl;

	runCircle(sourceSpr, targetSpr, radius, speed);
	

}




