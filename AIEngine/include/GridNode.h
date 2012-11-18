



#ifndef DEP_AI_NODE
#define DEP_AI_NODE
#define GRID_X 10
#define GRID_Y 10
#define ROAD 0
#define WALL 999
#define PLAYER 10


static int GridMap[GRID_X][GRID_Y] = {
	//      0        1        2     3     4     5     6    7      8    9   
		{   0,    WALL,       0,    0,    0,    0,    0, WALL,    0, WALL},//0
		{   0,       0,    WALL, WALL, WALL, WALL,    0, WALL, WALL,    0},//1
		{WALL,       0,       0,    0,    0,    0, WALL, WALL,    0, WALL},//2
		{   0,    WALL,    WALL, WALL,    0, WALL, WALL, WALL, WALL,    0},//3
		{   0,       0,       0,    0,    0, WALL,    0,    0,    0, WALL},//4
		{   0,       0,    WALL, WALL,    0,    0,    0, WALL, WALL,    0},//5
		{   0,       0,       0, WALL,    0, WALL,    0, WALL,    0, WALL},//6
		{   0,       0,    WALL,    0,    0, WALL,    0,    0,    0, WALL},//7
		{WALL,    WALL,    WALL, WALL, WALL, WALL,    0, WALL,    0,    0},//8
		{WALL,       0,       0, WALL,    0, WALL,    0,    0,    0,    0} //9
	};
/*
static int GridMap[GRID_X][GRID_Y] = {
	//   0  1  2  3  4  5  6  7  8  9   
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//0
		{0, WALL, 0, 0, 0, WALL, 0, 0, 0, 0},//1
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//2
		{0, 0, 0, 0, 0, WALL, 0, 0, 0 ,0},//3
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//4
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//5
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//6
		{0, 0, 0, 0, 0, WALL, 0, 0, 0 ,0},//7
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//8
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0} //9
	};*/

/*
static int GridMap[GRID_X][GRID_Y] = {
	//   0  1  2  3  4  5  6  7  8  9   
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//0
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//1
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//2
		{0, 0, 0, 0, 0, WALL, 0, 0, 0 ,0},//3
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//4
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//5
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//6
		{0, 0, 0, 0, 0, WALL, 0, 0, 0 ,0},//7
		{0, 0, 0, 0, 0, WALL, 0, 0, 0, 0},//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0} //9
	};
*/


class GridNode{
public:
	GridNode(int gridX, int gridY);
	~GridNode();
	float estimateDistance(GridNode* goalNode);
	bool isSameState(GridNode* goalNode);
	


public:
	GridNode* parent;
	GridNode* child;
	float f;//f = g + h�t��k���̮֤ߪ����|�����ƭ�
	float g;//���ʨ�Ӹ`�I������
	float h;//�q�ثe�`�I���ʨ�ؼи`�I���w���`�����A�S�Q�٬��u���~���ա]heuristic�^�v
	int gridX, gridY;//�b�����a�ϤW����l

};

#endif