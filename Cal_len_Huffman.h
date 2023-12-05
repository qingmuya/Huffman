#ifndef CAL_LEN_HUFFMAN_H_INCLUDED
#define CAL_LEN_HUFFMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

//ʹ��ͬһ���ṹ��ò�ƴ��ڳ�ͻ����C++����������д��ֻ�ܴ�������ṹ���ͬ���ܺ���

//���������Ĵ洢�ṹ
typedef struct{
    int weight;  //����Ȩ��
    int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}Htnode,*Huffmantree;

//������
void cal_len_huffman_tree(Huffmantree &HT);
//������������
void create_huffman_tree(Huffmantree &HT,int n);
//����������Сֵ
void Select(Huffmantree HT, int len, int &s1, int &s2);
//�����Ȩ·������
void cal(Huffmantree HT,int n);

#endif // CAL_LEN_HUFFMAN_H_INCLUDED
