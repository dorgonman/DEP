// stl includes
#include <algorithm>
#include <set>
#include <vector>
#include "GridNode.h"
using namespace std;
//實作演算法
//http://blog.minstrel.idv.tw/2004/12/star-algorithm.html
// swf.com.tw/?p=67 
 



#ifndef DEP_AI_ASTARSEARCH
#define DEP_AI_ASTARSEARCH


class AStarSearch{
public:
	AStarSearch();
	~AStarSearch();
	void setStartAndGoalNode(int startGridX, int startGridY, int goalGridX, int goalGridY);
	void beginSearch();
	//當執行完beginSearch()之後，最短路徑將會串接成為一個linkList
	//最前面會是startNode，最後面會是nowNode
	//因為現在正在處理的節點比對到goalNode的x, y之後就等於找到最短路徑而停止搜尋
	GridNode* getStartNode(){return startNode;};
	//After execute beginSearch(), nowNode will reach the goalNode;
	GridNode* getLastSearchNode(){return nowNode;};
	//注意：此節點只保存goalNode的節點資訊，其中並不會連結任何可以到達的路徑(因為有時候goalNode並沒辦法到達)
	GridNode* getGoalNode(){return goalNode;};
	
protected:
	virtual void expandNodes();
	virtual void checkCanMove(int gridX, int gridY, float cost);

private:
	void buildSolutionPath();
	void freeAllNodes();
public:
	vector<GridNode*> openList;
	vector<GridNode*> closedList;
	GridNode* startNode;
	GridNode* goalNode;
	GridNode* nowNode;//現在正在處理的節點

};





#endif