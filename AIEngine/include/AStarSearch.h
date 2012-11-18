// stl includes
#include <algorithm>
#include <set>
#include <vector>
#include "GridNode.h"
using namespace std;
//��@�t��k
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
	//����槹beginSearch()����A�̵u���|�N�|�걵�����@��linkList
	//�̫e���|�OstartNode�A�̫᭱�|�OnowNode
	//�]���{�b���b�B�z���`�I����goalNode��x, y����N������̵u���|�Ӱ���j�M
	GridNode* getStartNode(){return startNode;};
	//After execute beginSearch(), nowNode will reach the goalNode;
	GridNode* getLastSearchNode(){return nowNode;};
	//�`�N�G���`�I�u�O�sgoalNode���`�I��T�A�䤤�ä��|�s������i�H��F�����|(�]�����ɭ�goalNode�èS��k��F)
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
	GridNode* nowNode;//�{�b���b�B�z���`�I

};





#endif