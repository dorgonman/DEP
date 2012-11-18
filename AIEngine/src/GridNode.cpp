#include "GridNode.h"
#include "AStarSearch.h"

GridNode::GridNode(int _gridX, int _gridY){
	gridX = _gridX;
	gridY = _gridY;
	parent = NULL;
	child = NULL;
	g = h = 0;
	f = g + h;

}

GridNode::~GridNode(){
	//if(parent) delete parent;
	//if(child) delete child;
}


//計算二點之間的距離估算，使用曼哈頓區塊計算方法
//if h = 0, then algorithm is BFS
float GridNode::estimateDistance(GridNode *goalNode){
	float h = (float)(abs( goalNode->gridX - this->gridX )  + 
			   abs( goalNode->gridY - this->gridY )) * 10; 
	return h;

}

bool GridNode::isSameState(GridNode *goalNode){
		if(this->gridX == goalNode->gridX && 
			this->gridY == goalNode->gridY){
				return true;
		}
		return false;


}
