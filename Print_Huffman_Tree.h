#ifndef PRINT_HUFFMAN_TREE_H_INCLUDED
#define PRINT_HUFFMAN_TREE_H_INCLUDED

//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <climits>
#include "menu.h"

//���ó���
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define SUCCESS 1
#define UNSUCCESS -1

//�������Ͷ���
typedef int Status;

// ����������
typedef char TElemType;

// �������ṹ��
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
} BiTBode, *BiTree;

void start(HuffmanTree HT,int numofTree);

BiTree conversion(HuffmanTree HT,int num);

// ������Ҫ�Ľӿ�
// ����������Ϊ��������������������������
Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R);
// ��ȡ�������
int BiTreeDepth(BiTree T);

void print(BiTree Hb);

#endif
