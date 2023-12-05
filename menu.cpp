#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1��������������\n");
    printf("\t2�����ÿ���ַ��Ĺ���������\n");
    printf("\t3��������������Ĵ�Ȩ·������\n");
    printf("\t����ѡ��ǰ���ֵ��ù��ܣ�\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:
                //������������
                HuffmanTree HT;
                int n;
                cout<<"����������:\n";
                scanf("%d",&n);
                create_huffman_tree(HT,n);
                refresh();
                break;
            case 2:{
                //���ÿ���ַ���Ӧ�Ĺ���������
                HuffTree HT;
                print_huffman_code(HT);
                refresh();
                break;
            }
            case 3:{
                //�����Ȩ·������
                Huffmantree HT;
                cal_len_huffman_tree(HT);
                refresh();
                break;
            }
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
        }
    }
}

//ˢ�º���
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}
