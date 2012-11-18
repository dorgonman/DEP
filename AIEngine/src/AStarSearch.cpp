#include "AStarSearch.h"
#include <IOSTREAM>
AStarSearch::AStarSearch(){
	startNode = NULL;
	goalNode = NULL;
	nowNode = NULL;
	freeAllNodes();
}


AStarSearch::~AStarSearch(){
	freeAllNodes();
}




void AStarSearch::freeAllNodes(){

	vector< GridNode * >::iterator it;
	for( it = openList.begin(); it != openList.end(); it++ ){
			GridNode* n = *it;
			delete n;
			n = NULL;
	}

	for( it = closedList.begin(); it != closedList.end(); it++ ){
			GridNode* n = *it;
			delete n;
			n = NULL;
	}
	openList.clear();
	closedList.clear();	
	//因為startNode跟nowNode會在list被清除，所以只需delete goalNode就行了
	if(goalNode) delete goalNode;
	goalNode = NULL;

}



void AStarSearch::buildSolutionPath(){
	GridNode* solution = nowNode;

	//由現在這個節點往回找到solution path(主要工作是串接child)
	while(solution != NULL){
		//cout << solution->gridX << solution->gridY << endl;

		//如果是startNode的話，他的parent就會是NULL，所以說就不用去為NULL的child串接
		if(solution != startNode){
			solution->parent->child = solution;
		}

		
		solution = solution->parent;
	}
}

void AStarSearch::setStartAndGoalNode(int startGridX, int startGridY, int goalGridX, int goalGridY){

	freeAllNodes();

	startNode = new GridNode(startGridX, startGridY);
	goalNode = new GridNode(goalGridX, goalGridY);

	startNode->g = 0;
	startNode->h = startNode->estimateDistance(goalNode);
	startNode->f = startNode->g + startNode->h;
	//startNode->parent = NULL;


	openList.push_back(startNode);

}
void AStarSearch::beginSearch(){

    cout << "begin"<<endl;

	while(!openList.empty()){

		nowNode = openList[0];
		//cout << goalNode->gridX << goalNode->gridY << endl;
		//cout << nowNode->gridX << nowNode->gridY << nowNode->f << nowNode->parent << endl;

		//取得f最低的節點
		vector<GridNode*>::iterator it;
		for( it = openList.begin(); it != openList.end(); it++){
			GridNode* node = *it;
			//cout << "x:" << node->gridX << ", y:" << node->gridY << ", content:" << GridMap[node->gridX][node->gridY] << endl;
			if(node->f < nowNode->f){
				nowNode = node;	
			}	
		}

	//	cout << "now node:" << nowNode->gridX << nowNode->gridY <<   ", content:" << GridMap[nowNode->gridX][nowNode->gridY] << endl;
		//system("PAUSE");


			//把nowNode從openList中移除，加入closedList
		for( it = openList.begin(); it != openList.end(); it++){
			GridNode* node = *it;
			if(node == nowNode){
				//cout << node << nowNode << endl;
				openList.erase(it);
				break;
			}
		}

		closedList.push_back(nowNode);



		
		//到達目標
		if(nowNode->isSameState(goalNode)){
			buildSolutionPath();
			cout << "find path" << endl;
			return ;
		}

		expandNodes();

	}
	buildSolutionPath();
	cout << "找不到路徑" << endl;
	//nowNode = NULL;

	//return *nowNode;//沒有找到路徑


}

void AStarSearch::expandNodes(){
	int gridX, gridY;
	float cost;
	

		//左上
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY - 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//左
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY;
		cost = 10 + (float)GridMap[gridX][gridY] ;
		checkCanMove(gridX, gridY, cost);

		//左下
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY + 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//上
		gridX = nowNode->gridX;
		gridY = nowNode->gridY - 1;
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);


		//下
		gridX = nowNode->gridX;
		gridY = nowNode->gridY + 1;
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);



		//右上
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY - 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);
		
		//右
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY ;
		//cost = 10 + (float)GridMap[gridX][gridY] - 10 ;//這一格測試了文章中往右邊走會比往右下斜走還要好的路徑，所以如果成本用這個的話，就會繞彎路
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//右下
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY + 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, 14);
}


void AStarSearch::checkCanMove(int gridX, int gridY, float cost){

	vector<GridNode*>::iterator it;
	for( it = closedList.begin(); it != closedList.end(); it++){
		GridNode* node = *it;
		//此節點存在於closedList，不處理
		if(node->gridX == gridX &&
			node->gridY == gridY){
			return;
		}
	}


	GridNode* canMoveNode;
	//在地圖範圍內的節點我們才處理
		if(gridX >= 0 && 
		   gridY >= 0 && 
		   gridX < GRID_X &&
		   gridY < GRID_Y){
			   
			
			 //能通過的節點才處理
			if(GridMap[gridX][gridY] != 999){

				//若canMoveNode已經存在於openList則判斷這個新計算出來移動到canMoveNode是否更好，沒有的話則略過
				bool alreadyExist = false;
				for( it = openList.begin(); it != openList.end(); it++){
					GridNode* node = *it;
					
					//此節點存在於openList
					if(node->gridX == gridX &&
						node->gridY == gridY ){
							canMoveNode = node;
							//用轉直角的方式，如果現在走的這條路的成本有比直接走過去還好的話，就繞遠路(檢查現在走的這條路徑是否更好)
							//基本上如果是用基本的垂直水平成本10跟對角成本14的做法時，
							//這個機制是沒有作用的(就文章中的例子，新找到的路永遠是不會更好，因為20 > 14)
							//當我們在GridMap中對每一個附加地型成本時或是走對角成本會比較低時，此機制才真正有作用
							//運用的方法有很多，看自己的設計
							if((nowNode->g + cost)  < canMoveNode->g){
								canMoveNode->parent = nowNode;
								canMoveNode->g = canMoveNode->parent->g + cost;
								canMoveNode->f = canMoveNode->g + canMoveNode->h;
							
							}
				

							alreadyExist = true;
					}

				}



				//如果節點不在開啟列表裡，我們就要new出一個新的節點出來，並計算這一格g、h、f
				//之後加入到openList裡
				if(!alreadyExist){
					canMoveNode = new GridNode(gridX, gridY);
					canMoveNode->parent = nowNode;	
					canMoveNode->g = canMoveNode->parent->g + cost;
					canMoveNode->h = canMoveNode->estimateDistance(goalNode);
					canMoveNode->f = canMoveNode->g + canMoveNode->h;
					openList.push_back(canMoveNode);

				}
			}
		}

}

