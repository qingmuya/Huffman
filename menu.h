#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>//c++��
#include<algorithm>//�㷨��
#include <string>//�ַ���
#include <fstream>
#include <vector>
#include <cmath>


#include "Create_Huffman_tree.h"
#include "Decode.h"
#include "Encode_char.h"
#include "Encode_string.h"
#include "Get_weight_char.h"
#include "Print_Huffman_Tree.h"

//���������Ĵ洢�ṹ
typedef struct{
    char ch;
    double weight;  //����Ȩ��
    int parent, lchild, rchild;  //����˫�ס����ӡ��Һ��ӵ��±�
}HTNode,*HuffmanTree;

//�˵�����
void menu();
//ˢ�º���
void refresh();
//ѡ����
void Selectmenu();

#endif // MENU_H_INCLUDED
