#include "menu.h"

using namespace std;

// ��ȡ�������
int BiTreeDepth(HuffmanTree HT,int m) {
	//�Ȳ���Ȩֵ��С�Ľڵ�������������ڵĲ�����Ϊ���
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

/*
* �ݹ��ӡ��ӡ������
* T		���ڴ�ӡ����
* depth	Ŀǰ�ڴ�ӡ���ĵڼ���
* right	�������Ƿ�Ϊ������
* tap	Ŀǰ������Ҫ�����ƫ������
*/
Status Traverse_R(HuffmanTree HT, int depth, int right, int tap,int m) {
	if (HT == NULL){
        return OK;
	}

	// ��ȡһ�����ĳ�ʼ�߶ȣ����ڼ������ƫ������
	static int treeDepth = BiTreeDepth(HT,m);
	// ��¼��ǰ���λ�ã������ڵݹ��м�¼��ǰ�ݹ�ʱ����λ��
	int x, y;
	// �����������������������ֿ���

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
	printf("%.2f",HT[m].weight);

	// �ڴ�ӡ����ʱ����ǰ����+1
	depth++;
	// ���������ĸ�ƫ����
	tap = tap * 2 + (right == 1 ? 2 : 0);
	if (HT[m].lchild == NULL && HT[m].rchild == NULL) return OK;
	else if (HT[m].rchild == NULL) {
		// ��ӡ��������λ��
		gotoxy(x * 2 - tap3, y + 1);
		printf("��");
		for (int i = 0; i < tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(HT, depth, 0, tap , HT[m].lchild);
	}
	else if (HT[m].lchild == NULL) {
		// ��ӡ��������λ��
		gotoxy(x * 2, y + 1);
		printf("��");
		for (int i = 0; i < tap3-1; i++) printf("��");
		printf("��");
		Traverse_R(HT, depth, 1, tap , HT[m].rchild);
	}
	else {
		// ��ӡ����������λ��
		gotoxy(x * 2 - tap3, y + 1);
		printf("��");
		for (int i = 0; i < tap3 - 1; i++) printf("��");
		printf("��");
		for (int i = 0; i < tap3 - 1; i++) printf("��");
		printf("��");
		Traverse_R(HT, depth, 0, tap , HT[m].lchild);
		Traverse_R(HT, depth, 1, tap , HT[m].rchild);
	}
}

// ��ӡ���νӿ�
Status Traverse(HuffmanTree HT,int m) {
    system("cls");
	Traverse_R(HT, 0, 0, 0,m - 1);
	return OK;
}
