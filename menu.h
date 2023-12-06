#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>//c++库
#include<algorithm>//算法库
#include <string>//字符串
#include <fstream>
#include <vector>
#include <cmath>


#include "Create_Huffman_tree.h"
#include "Decode.h"
#include "Encode_char.h"
#include "Encode_string.h"
#include "Get_weight_char.h"
#include "Print_Huffman_Tree.h"

//哈夫曼树的存储结构
typedef struct{
    char ch;
    double weight;  //结点的权重
    int parent, lchild, rchild;  //结点的双亲、左孩子、右孩子的下标
}HTNode,*HuffmanTree;

//菜单函数
void menu();
//刷新函数
void refresh();
//选择函数
void Selectmenu();

#endif // MENU_H_INCLUDED
