#include "hge.h"
#include <vector>
#include "HitPoint.h"
#include "IOSTREAM"
#include "AStarSearch.h"
using namespace std;

#pragma comment(lib, "hge.lib")
#pragma comment(lib, "hgehelp.lib")


#ifndef DEP_AI
#define DEP_AI

class DEPSprite;


class AIEngine{
public://路徑尋找方式
	AIEngine();
	~AIEngine();
	void randomJump(DEPSprite* spr);
	void randomSearch(DEPSprite* spr);
	void randomSearch(float *_x, float *_y);
	void searchTarget(DEPSprite* sourceSpr, float targetX, float targetY, float radius = 1000);
	void searchTarget(DEPSprite* sourceSpr, DEPSprite* targetSpr, float radius = 1000);
	void astarPathSearch(float sourceX, float sourceY, float targetX, float targetY);
	void astarPathSearch(DEPSprite* sourceSpr, float targetX, float targetY);
	void astarPathSearch(DEPSprite* sourceSpr, DEPSprite* targetSpr);
	




public://路徑運行模式
	static void runToTarget(vector<DEPSprite*> sprs);
	static void runToTarget(DEPSprite* spr);
	static void runToTarget(DEPSprite *spr, float targetX, float targetY);
	static void runTo(DEPSprite* spr, float theta);
	bool runAstarPath(DEPSprite* sourceSpr);
	void bounce(DEPSprite* spr);
	void runCircle(DEPSprite *sourceSpr, DEPSprite *targetSpr, float radius = 50, float speed = 10, float startTheta = 0);
	////用radiusAddSpeed來控制是否要有向內轉的機制
	//負數會向內轉完再轉向外面
	void runSpiral(DEPSprite *sourceSpr, DEPSprite *targetSpr, float speed = 1, unsigned long minRadius = 1, unsigned long maxRadius = 1000, float radiusAddSpeed = 6.5);


public:
	void renderAstarPath(HTEXTURE tex);
	//void renderAstarNode(


public:
	void setMapRange(float x, float y, float width, float height);
	static bool distancePointLine(float pointX, float pointY, float LineStartX, float LineStartY, float LineEndX, float LineEndY, float* distance);
	int GetGridMapContent(float x, float y );
	void mapPositionToGrid(float realX, float realY, int* gridX, int* gridY);

private:
	float mapX;
	float mapY;
	float mapWidth ;
	float mapHeight;
	int gridWidth, gridHeight;//將真實地圖的座標轉換成虛擬地圖時每一個GRID的大小
	HGE*   hge;
	HitPoint* hitPoint;
	AStarSearch* astar;
	GridNode* solutionPath;
};

#endif

