#include "menu.h"

using namespace std;

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

// 获取树的深度
int BiTreeDepth(BiTree T) {
	if (T == NULL) return 0;

	int depthLeft, depthRight;
	depthLeft = BiTreeDepth(T->lchild);
	depthRight = BiTreeDepth(T->rchild);

	return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
}

// 将二叉树分为根，左子树，右子树三个部分
Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R) {
	if (T == NULL) return ERROR;
	L = T->lchild;
	R = T->rchild;

	return OK;
}

Status Traverse_R(BiTree T, int depth, int right, int tap) {
	if (T == NULL) return OK;

	// 获取一次树的初始高度，用于计算相对偏移数量
	static int treeDepth = BiTreeDepth(T);   //
	// 记录当前光标位置，用于在递归中记录当前递归时树的位置
	int x, y;
	// 拆分树，将树的左右子树拆分开来
	BiTree L, R;
	BreakBiTree(T, L, R);

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
	cout<<T->data;

	// 在打印子树时，当前层数+1
	depth++;
	// 计算子树的父偏移量
	tap = tap * 2 + (right == 1 ? 2 : 0);
	if (L == NULL && R == NULL) return OK;
	else if (R == NULL) {
		// 打印左子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┛");
		Traverse_R(L, depth, 0, tap);
	}
	else if (L == NULL) {
		// 打印右子树的位置
		gotoxy(x * 2, y + 1);
		printf("┗");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┓");
		Traverse_R(R, depth, 1, tap);
	}
	else {
		// 打印左右子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┻");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┓");
		Traverse_R(L, depth, 0, tap);
		Traverse_R(R, depth, 1, tap);
	}
}

// 打印树形接口
Status Traverse(BiTree T) {
	Traverse_R(T, 0, 0, 0);
	return OK;
}

BiTree conversion(HuffmanTree HT,int num){
    BiTree Hb = new BiTNode;
    Hb->data = HT[num].ch;
    if(HT[num].lchild != -1 && HT[num].rchild != -1){
        Hb->lchild = conversion(HT,HT[num].lchild);
        Hb->rchild = conversion(HT,HT[num].rchild);
    }
    else if(HT[num].lchild != -1){
        Hb->lchild = conversion(HT,HT[num].lchild);
        Hb->rchild = NULL;
    }
    else if(HT[num].rchild != -1){
        Hb->rchild = conversion(HT,HT[num].rchild);
        Hb->lchild = NULL;
    }
    else{
        Hb->rchild = NULL;
        Hb->lchild = NULL;
    }
    return Hb;
}

void start(HuffmanTree HT,int num){
    BiTree Hb = conversion(HT,num);
    system("cls");
    Traverse(Hb);
}
