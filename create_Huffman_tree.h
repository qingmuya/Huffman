#ifndef CREATE_HUFFMAN_TREE_H_INCLUDED
#define CREATE_HUFFMAN_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "menu.h"

using namespace std;

//哈夫曼树的存储结构
typedef struct{
    char ch;
    double weight;  //结点的权重
    int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;

//创建哈夫曼树
HuffmanTree Create_Huffman_tree(vector<double> arr);
//返回两个最小值
void Select(HuffmanTree HT, int len, int &s1, int &s2);
//打印输出函数
void output(HuffmanTree HT,int n);

#endif // CREATE_HUFFMAN_TREE_H_INCLUDED
