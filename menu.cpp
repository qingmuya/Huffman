#include "menu.h"

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1����ȡ�ַ�Ȩ��\n");
    printf("\t2��������������\n");
    printf("\t3������������\n");
    printf("\t4������\n");
    printf("\t4������\n");
    printf("\t4����ӡ��������\n");
    printf("\t����ѡ��ǰ���ֵ��ù��ܣ�\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:{
                //��ȡ�ַ�Ȩ�أ�����file.txt�ļ���ȡ�ַ���Ȩ��
                vector<double> arr=Get_weight_char();
                cout<<"sum:"<<arr[0]<<endl;
                for(int i = 1;i<=26;i++){
                    cout<<(char)('a'+i-1)<<":"<<arr[i]<<endl;
                }
                refresh();
                break;
            }
            case 2:{
                //���������������������������������ļ���HfmTree.txt
                //Create_Huffman_tree();
                refresh();
                break;
            }
            case 3:{
                //���룺����HfmTree.txt���ÿ���ַ��Ĺ��������룬Ȼ�󽫽�������ļ�CodeFile.txt�С�
                Encode_char();
                refresh();
                break;
            }
            case 4:{
                //���ܣ����ݱ��뽫file.txt�ļ����ܣ��������TextFile.txt
                Encode_string();
                refresh();
                break;
            }
            case 5:{
                //���룺��ȡTextFile.txt�ļ����룬�������룬����ʾ�����
                Decode();
                refresh();
                break;
            }
            case 6:{
                //��ӡ��������
                Print_Huffman_Tree();
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
