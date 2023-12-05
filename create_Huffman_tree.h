#ifndef CREATE_HUFFMAN_TREE_H_INCLUDED
#define CREATE_HUFFMAN_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

//ʹ��ͬһ���ṹ��ò�ƴ��ڳ�ͻ����C++����������д��ֻ�ܴ�������ṹ���ͬ���ܺ���

//���������Ĵ洢�ṹ
typedef struct{
    int weight;  //����Ȩ��
    int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode,*HuffmanTree;

//������������
void create_huffman_tree(HuffmanTree &HT,int n);
//����������Сֵ
void Select(HuffmanTree HT, int len, int &s1, int &s2);
//��ӡ�������
void print(HuffmanTree HT,int n);

#endif // CREATE_HUFFMAN_TREE_H_INCLUDED
