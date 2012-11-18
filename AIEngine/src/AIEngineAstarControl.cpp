#include "AIEngine.h"
#include "DEPSprite.h"

void AIEngine::astarPathSearch(float sourceX, float sourceY, float targetX, float targetY){
	int startGridX, startGridY;
	this->mapPositionToGrid(sourceX, sourceY, &startGridX, &startGridY);
	int goalGridX, goalGridY;
	this->mapPositionToGrid(targetX, targetY, &goalGridX, &goalGridY);
	astar->setStartAndGoalNode(startGridX, startGridY, goalGridX, goalGridY);
	astar->beginSearch();
	solutionPath = astar->getStartNode();
	GridNode* solution = astar->getStartNode();
	cout << "solution path:" << endl;
	while(solution != NULL){
		cout << solution->gridX << solution->gridY << endl;
		solution = solution->child;
	}
/*
	solution = astar->getLastSearchNode();
	while(solution != NULL){
		cout << solution->gridX << solution->gridY << endl;
		solution = solution->parent;
	}*/

	cout << "startGrid and goalGrid" << endl;
	cout << startGridX << startGridY << endl;
	cout << goalGridX <<  goalGridY << endl;
}


void AIEngine::astarPathSearch(DEPSprite *sourceSpr, DEPSprite *targetSpr){
	astarPathSearch(sourceSpr->x, sourceSpr->y, targetSpr->x, targetSpr->y);
}


void AIEngine::astarPathSearch(DEPSprite *sourceSpr, float targetX, float targetY){
	astarPathSearch(sourceSpr->x, sourceSpr->y, targetX, targetY);
}




bool AIEngine::runAstarPath(DEPSprite* sourceSpr){
	float gridBias = 20;

	if(solutionPath != NULL){
		//cout << solutionPath->gridX << solutionPath->gridY << endl;
		//cout << sourceSpr->targetX << ":" << sourceSpr->targetY << endl;
		//system("PAUSE");
		runToTarget(sourceSpr, (solutionPath->gridX) * gridWidth + gridBias, solutionPath->gridY * gridHeight + gridBias);

		
		if(sourceSpr->getHitPoint()->TestPoint(sourceSpr->targetX, sourceSpr->targetY)){
			cout << "target grid and target position:" << endl;
			cout << solutionPath->gridX << solutionPath->gridY << endl;
			cout << sourceSpr->targetX << ":" << sourceSpr->targetY << endl;
			solutionPath = solutionPath->child;
			//system("PAUSE");
		}
		return true;
	}
	return false;
}






void AIEngine::renderAstarPath(HTEXTURE tex){
	static DEPSprite spr(tex, 0, 0, 80, 60);
	spr.SetTexture(tex);
	spr.setColor(0xFF00FF00);
	GridNode* renderNode = astar->getStartNode();
	while(renderNode != NULL){
		spr.Render(renderNode->gridX * gridWidth, renderNode->gridY * gridHeight);
		renderNode = renderNode->child;
	}

	//µe¥XÀY§À
	renderNode = astar->getStartNode();
	if(renderNode != NULL){
		spr.setColor(0xFFFF0000);
		spr.Render(renderNode->gridX * gridWidth, renderNode->gridY * gridHeight);
	}

	renderNode = astar->getLastSearchNode();
	if(renderNode != NULL){
		spr.setColor(0xFF0000FF);
		spr.Render(renderNode->gridX * gridWidth, renderNode->gridY * gridHeight);
	}

	
	renderNode = astar->getGoalNode();
	if(renderNode != NULL){
		spr.setColor(0xFFFF00FF);
		spr.Render(renderNode->gridX * gridWidth, renderNode->gridY * gridHeight);
	}
}