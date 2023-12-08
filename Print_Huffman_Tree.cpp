#include "menu.h"

using namespace std;

// 获取树的深度
int BiTreeDepth(HuffmanTree HT,int m) {
	//先查找权值最小的节点的索引，其所在的层数即为深度
	double min_num = INT_MAX;
	int x = 0,index_of_min;
	while(x < m){
		if(min_num > HT[x].weight){
			min_num = HT[x].weight;
			index_of_min = x;
		}
		x++;
	}

	int depth = 0;
	while(HT[index_of_min].parent != NULL){
		index_of_min = HT[index_of_min].parent;
		depth++;
	}

	return depth;
}

//改变光标位置
void gotoxy(int x, int y)
{
	// 更新光标位置
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}

/*
* 递归打印打印出树形
* T		正在打印的树
* depth	目前在打印树的第几层
* right	该子树是否为右子树
* tap	目前子树需要的相对偏移数量
*/
Status Traverse_R(HuffmanTree HT, int depth, int right, int tap,int m) {
	if (HT == NULL){
        return OK;
	}

	// 获取一次树的初始高度，用于计算相对偏移数量
	static int treeDepth = BiTreeDepth(HT,m);
	// 记录当前光标位置，用于在递归中记录当前递归时树的位置
	int x, y;
	// 拆分树，将树的左右子树拆分开来

	// 计算父树的偏移量
	int tap1 = tap * pow(2, treeDepth - depth);
	// 计算子树的偏移量
	int tap2 = right * (pow(2, treeDepth - depth));
	// 计算半偏移量
	int tap3 = pow(2, treeDepth - depth - 1);

	// 获取根的坐标
	// x 计算方法为：父偏移量 + 子偏移量 + 半偏移量 - 1
	// y 计算方法为：目前打印的层数 * 2
	x = tap1 + tap2 + tap3 - 1;
	y = depth * 2;

	// 打印根的位置
	gotoxy(x * 2, y);
	printf("%.2f",HT[m].weight);

	// 在打印子树时，当前层数+1
	depth++;
	// 计算子树的父偏移量
	tap = tap * 2 + (right == 1 ? 2 : 0);
	if (HT[m].lchild == NULL && HT[m].rchild == NULL) return OK;
	else if (HT[m].rchild == NULL) {
		// 打印左子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┛");
		Traverse_R(HT, depth, 0, tap , HT[m].lchild);
	}
	else if (HT[m].lchild == NULL) {
		// 打印右子树的位置
		gotoxy(x * 2, y + 1);
		printf("┗");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┓");
		Traverse_R(HT, depth, 1, tap , HT[m].rchild);
	}
	else {
		// 打印左右子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┻");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┓");
		Traverse_R(HT, depth, 0, tap , HT[m].lchild);
		Traverse_R(HT, depth, 1, tap , HT[m].rchild);
	}
}

// 打印树形接口
Status Traverse(HuffmanTree HT,int m) {
    system("cls");
	Traverse_R(HT, 0, 0, 0,m - 1);
	return OK;
}
