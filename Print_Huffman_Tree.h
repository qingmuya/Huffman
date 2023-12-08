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
typedef int TElemType;

// �������ṹ��
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
} BiTBode, *BiTree;

// ������Ҫ�Ľӿ�
// ��ȡ�������
int BiTreeDepth(HuffmanTree HT,int m);

Status Traverse(HuffmanTree HT,int m);

#endif // PRINT_HUFFMAN_TREE_H_INCLUDED



