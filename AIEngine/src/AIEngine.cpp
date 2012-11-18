#include "AIEngine.h"
#include "DEPSprite.h"
#include "math.h"






AIEngine::AIEngine(){
	setMapRange(0, 0, 800, 600);	
	this->hge = hgeCreate(HGE_VERSION);
	this->hge->Random_Seed();
	hitPoint = new HitPoint(new hgeRect(), 10);
	gridWidth = (int)mapWidth / GRID_X;
	gridHeight = (int)mapHeight / GRID_Y;
	astar = new AStarSearch();
	solutionPath = NULL;
}

AIEngine::~AIEngine(){
	this->hge->Release();
	if(hitPoint) delete hitPoint;
	if(astar)    delete astar;
	hitPoint = NULL;
	astar = NULL;
	solutionPath = NULL;
}


void AIEngine::setMapRange(float _x, float _y, float _width, float _height){
	mapX = _x;
	mapY = _y;
	mapWidth = _width;
	mapHeight = _height;
	gridWidth = (int)mapWidth / GRID_X;
	gridHeight = (int)mapHeight / GRID_Y;
}




void AIEngine::bounce(DEPSprite *spr){

	if(spr->x > mapWidth){
		spr->setVelocity(-spr->getVelocityX(), -spr->getVelocityY());
		spr->setTheta(-spr->getTheta());
	}
	
	if (spr->x < mapX){
		spr->setVelocity(-spr->getVelocityX(), -spr->getVelocityY());
		spr->setTheta(-spr->getTheta());
	}

	if(spr->y > mapHeight){		
		spr->setTheta(-spr->getTheta());
	}
	
	if (spr->y < mapY){		
		spr->setTheta(-spr->getTheta());
	}

}


void AIEngine::mapPositionToGrid(float realX, float realY, int *gridX, int *gridY){
	*gridX = (int)((realX / gridWidth));
	*gridY = (int)((realY / gridHeight));
	if( realX < 0){
		*gridX = -1;
	}
	
	if(realY < 0){
		*gridY = -1;
	}


}

int AIEngine::GetGridMapContent( float x, float y ){
	int gridX, gridY;

	this->mapPositionToGrid(x, y, &gridX, &gridY);
	if( gridX < 0 ||
	    gridX >= GRID_X  ||
		 gridY < 0 ||
		 gridY >= GRID_Y  
	  )
	{
		return WALL;	 
	}

	/*
	cout << "real position(在測試程式中會再加上估算移動值):";
	cout << x << ":" << y << endl;
	cout << "gridWidth and gridHeight:";
	cout << gridWidth << ":" << gridHeight << endl;
	cout << "gridContent:";
	cout << GridMap[gridX][gridY] << endl;
	cout << "grid position:";
	cout << gridX << ":" << gridY << endl;
	cout << endl;*/

	return GridMap[gridX][gridY];
}


