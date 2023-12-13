#ifndef PRINT_HUFFMAN_TREE_H_INCLUDED
#define PRINT_HUFFMAN_TREE_H_INCLUDED

//常用头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <climits>
#include "menu.h"

//常用常量
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define SUCCESS 1
#define UNSUCCESS -1

//常用类型定义
typedef int Status;

// 树数据类型
typedef char TElemType;

// 二叉树结构体
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
} BiTBode, *BiTree;

void start(HuffmanTree HT,int numofTree);

BiTree conversion(HuffmanTree HT,int num);

// 部分需要的接口
// 将二叉树分为根，左子树，右子树三个部分
Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R);
// 获取树的深度
int BiTreeDepth(BiTree T);

void print(BiTree Hb);

#endif
