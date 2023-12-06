#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>//c++¿â
#include<algorithm>//Ëã·¨¿â
#include <string>//×Ö·û´®
#include <fstream>
#include <vector>
#include <cmath>


#include "Create_Huffman_tree.h"
#include "Decode.h"
#include "Encode_char.h"
#include "Encode_string.h"
#include "Get_weight_char.h"
#include "Print_Huffman_Tree.h"

//²Ëµ¥º¯Êý
void menu();
//Ë¢ÐÂº¯Êý
void refresh();
//Ñ¡Ôñº¯Êý
void Selectmenu();

#endif // MENU_H_INCLUDED
