#ifndef CREATE_HUFFMAN_TREE_H_INCLUDED
#define CREATE_HUFFMAN_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "menu.h"

using namespace std;

//���������Ĵ洢�ṹ
typedef struct{
    char ch;
    double weight;  //����Ȩ��
    int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode,*HuffmanTree;

//������������
HuffmanTree Create_Huffman_tree(vector<double> arr);
//����������Сֵ
void Select(HuffmanTree HT, int len, int &s1, int &s2);
//��ӡ�������
void output(HuffmanTree HT,int n);

#endif // CREATE_HUFFMAN_TREE_H_INCLUDED
