#ifndef PRINT_HUFFMAN_CODE_H_INCLUDED
#define PRINT_HUFFMAN_CODE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

//ʹ��ͬһ���ṹ��ò�ƴ��ڳ�ͻ����C++����������д��ֻ�ܴ�������ṹ���ͬ���ܺ���

//���������Ĵ洢�ṹ
typedef struct{
    char data;
    int weight;  //����Ȩ��
    string code;
    int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTnode,*HuffTree;
//����������ṹ��
typedef char **HuffmanCode;
//������
void print_huffman_code(HuffTree &HT);
//���ݹ��������������������
void CreateHuffmanCode(HuffTree HT,HuffmanCode &HC,int n);
//������������
void create_huffmantree(HuffTree &HT,int n);
//����������Сֵ
void Select(HuffTree HT, int len, int &s1, int &s2);

#endif // PRINT_HUFFMAN_CODE_H_INCLUDED
