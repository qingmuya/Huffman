#include "menu.h"

using namespace std;

//�ı���λ��
void gotoxy(int x, int y)
{
	// ���¹��λ��
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}

// ��ȡ�������
int BiTreeDepth(BiTree T) {
	if (T == NULL) return 0;

	int depthLeft, depthRight;
	depthLeft = BiTreeDepth(T->lchild);
	depthRight = BiTreeDepth(T->rchild);

	return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
}

// ����������Ϊ��������������������������
Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R) {
	if (T == NULL) return ERROR;
	L = T->lchild;
	R = T->rchild;

	return OK;
}

Status Traverse_R(BiTree T, int depth, int right, int tap) {
	if (T == NULL) return OK;

	// ��ȡһ�����ĳ�ʼ�߶ȣ����ڼ������ƫ������
	static int treeDepth = BiTreeDepth(T);   //
	// ��¼��ǰ���λ�ã������ڵݹ��м�¼��ǰ�ݹ�ʱ����λ��
	int x, y;
	// �����������������������ֿ���
	BiTree L, R;
	BreakBiTree(T, L, R);

	// ���㸸����ƫ����
	int tap1 = tap * pow(2, treeDepth - depth);
	// ����������ƫ����
	int tap2 = right * (pow(2, treeDepth - depth));
	// �����ƫ����
	int tap3 = pow(2, treeDepth - depth - 1);

	// ��ȡ��������
	// x ���㷽��Ϊ����ƫ���� + ��ƫ���� + ��ƫ���� - 1
	// y ���㷽��Ϊ��Ŀǰ��ӡ�Ĳ��� * 2
	x = tap1 + tap2 + tap3 - 1;
	y = depth * 2;

	// ��ӡ����λ��
	gotoxy(x * 2, y);
	cout<<T->data;

	// �ڴ�ӡ����ʱ����ǰ����+1
	depth++;
	// ���������ĸ�ƫ����
	tap = tap * 2 + (right == 1 ? 2 : 0);
	if (L == NULL && R == NULL) return OK;
	else if (R == NULL) {
		// ��ӡ��������λ��
		gotoxy(x * 2 - tap3, y + 1);
		printf("��");
		for (int i = 0; i < tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(L, depth, 0, tap);
	}
	else if (L == NULL) {
		// ��ӡ��������λ��
		gotoxy(x * 2, y + 1);
		printf("��");
		for (int i = 0; i < tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(R, depth, 1, tap);
	}
	else {
		// ��ӡ����������λ��
		gotoxy(x * 2 - tap3, y + 1);
		printf("��");
		for (int i = 0; i < tap3 - 1; i++) printf("��");
		printf("��");
		for (int i = 0; i < tap3 - 1; i++) printf("��");
		printf("��");
		Traverse_R(L, depth, 0, tap);
		Traverse_R(R, depth, 1, tap);
	}
}

// ��ӡ���νӿ�
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
