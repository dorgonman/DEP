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
	//�]��startNode��nowNode�|�blist�Q�M���A�ҥH�u��delete goalNode�N��F
	if(goalNode) delete goalNode;
	goalNode = NULL;

}



void AStarSearch::buildSolutionPath(){
	GridNode* solution = nowNode;

	//�Ѳ{�b�o�Ӹ`�I���^���solution path(�D�n�u�@�O�걵child)
	while(solution != NULL){
		//cout << solution->gridX << solution->gridY << endl;

		//�p�G�OstartNode���ܡA�L��parent�N�|�ONULL�A�ҥH���N���Υh��NULL��child�걵
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

		//���of�̧C���`�I
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


			//��nowNode�qopenList�������A�[�JclosedList
		for( it = openList.begin(); it != openList.end(); it++){
			GridNode* node = *it;
			if(node == nowNode){
				//cout << node << nowNode << endl;
				openList.erase(it);
				break;
			}
		}

		closedList.push_back(nowNode);



		
		//��F�ؼ�
		if(nowNode->isSameState(goalNode)){
			buildSolutionPath();
			cout << "find path" << endl;
			return ;
		}

		expandNodes();

	}
	buildSolutionPath();
	cout << "�䤣����|" << endl;
	//nowNode = NULL;

	//return *nowNode;//�S�������|


}

void AStarSearch::expandNodes(){
	int gridX, gridY;
	float cost;
	

		//���W
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY - 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//��
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY;
		cost = 10 + (float)GridMap[gridX][gridY] ;
		checkCanMove(gridX, gridY, cost);

		//���U
		gridX = nowNode->gridX - 1;
		gridY = nowNode->gridY + 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//�W
		gridX = nowNode->gridX;
		gridY = nowNode->gridY - 1;
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);


		//�U
		gridX = nowNode->gridX;
		gridY = nowNode->gridY + 1;
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);



		//�k�W
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY - 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);
		
		//�k
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY ;
		//cost = 10 + (float)GridMap[gridX][gridY] - 10 ;//�o�@����դF�峹�����k�䨫�|�񩹥k�U�ר��٭n�n�����|�A�ҥH�p�G�����γo�Ӫ��ܡA�N�|¶�s��
		cost = 10 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, cost);

		//�k�U
		gridX = nowNode->gridX + 1;
		gridY = nowNode->gridY + 1;
		cost = 14 + (float)GridMap[gridX][gridY];
		checkCanMove(gridX, gridY, 14);
}


void AStarSearch::checkCanMove(int gridX, int gridY, float cost){

	vector<GridNode*>::iterator it;
	for( it = closedList.begin(); it != closedList.end(); it++){
		GridNode* node = *it;
		//���`�I�s�b��closedList�A���B�z
		if(node->gridX == gridX &&
			node->gridY == gridY){
			return;
		}
	}


	GridNode* canMoveNode;
	//�b�a�Ͻd�򤺪��`�I�ڭ̤~�B�z
		if(gridX >= 0 && 
		   gridY >= 0 && 
		   gridX < GRID_X &&
		   gridY < GRID_Y){
			   
			
			 //��q�L���`�I�~�B�z
			if(GridMap[gridX][gridY] != 999){

				//�YcanMoveNode�w�g�s�b��openList�h�P�_�o�ӷs�p��X�Ӳ��ʨ�canMoveNode�O�_��n�A�S�����ܫh���L
				bool alreadyExist = false;
				for( it = openList.begin(); it != openList.end(); it++){
					GridNode* node = *it;
					
					//���`�I�s�b��openList
					if(node->gridX == gridX &&
						node->gridY == gridY ){
							canMoveNode = node;
							//���ઽ�����覡�A�p�G�{�b�����o�������������񪽱����L�h�٦n���ܡA�N¶����(�ˬd�{�b�����o�����|�O�_��n)
							//�򥻤W�p�G�O�ΰ򥻪�������������10��﨤����14�����k�ɡA
							//�o�Ӿ���O�S���@�Ϊ�(�N�峹�����Ҥl�A�s��쪺���û��O���|��n�A�]��20 > 14)
							//��ڭ̦bGridMap����C�@�Ӫ��[�a�������ɩάO���﨤�����|����C�ɡA������~�u�����@��
							//�B�Ϊ���k���ܦh�A�ݦۤv���]�p
							if((nowNode->g + cost)  < canMoveNode->g){
								canMoveNode->parent = nowNode;
								canMoveNode->g = canMoveNode->parent->g + cost;
								canMoveNode->f = canMoveNode->g + canMoveNode->h;
							
							}
				

							alreadyExist = true;
					}

				}



				//�p�G�`�I���b�}�ҦC��̡A�ڭ̴N�nnew�X�@�ӷs���`�I�X�ӡA�íp��o�@��g�Bh�Bf
				//����[�J��openList��
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

