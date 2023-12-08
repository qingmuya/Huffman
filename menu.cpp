#include "menu.h"

HuffmanCode HC;//�����������
HuffmanTree HT =NULL;//��������
vector<double> arr = Get_weight_char();
vector<char> ch;

void menu(){
    printf("\t*****��ӭʹ�����¹���****\n");
    printf("\t0���˳�\n");
    printf("\t1����ȡ�ַ�Ȩ��\n");
    printf("\t2��������������\n");
    printf("\t3������������\n");
    printf("\t4������\n");
    printf("\t5������\n");
    printf("\t6����ӡ��������\n");
    printf("\t��������ѡ��ǰ���������ù��ܣ�\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                cout<<"�˳��ɹ�"<<endl;
                exit(1);
            case 1:{
                //��ȡ�ַ�Ȩ�أ�����file.txt�ļ���ȡ�ַ���Ȩ��
                arr = Get_weight_char();
                cout<<"��ȡ�ַ���Ȩ�سɹ�"<<endl;
                refresh();
                break;
            }
            case 2:{
                //���������������������������������ļ���HfmTree.txt
                HT = Create_Huffman_tree(arr);
                int n = 0;  //n�����洢Ȩ�ز�Ϊ0�Ľ�������
                for(int i = 1;i < arr.size() - 1;i++){
                    if(arr[i] != 0){
                        n++;
                    }
                }
                output(HT,n * 2 - 1);
                cout<<"�ѽ���������������ļ���HfmTree.txt"<<endl;
                refresh();
                break;
            }
            case 3:{
                //���룺����HfmTree.txt���ÿ���ַ��Ĺ��������룬Ȼ�󽫽�������ļ�CodeFile.txt�С�
                Encode_char(arr,HC,HT,ch);
                cout<<"ÿ���ַ��Ĺ����������Ѿ��������ļ�:CodeFile.txt"<<endl;
                refresh();
                break;
            }
            case 4:{
                //���ܣ����ݱ��뽫file.txt�ļ����ܣ��������TextFile.txt
                Encode_string(ch,HC);
                cout<<"���ܺ�Ķ����Ѿ��������ļ�:TextFile.txt"<<endl;
                refresh();
                break;
            }
            case 5:{
                //���룺��ȡTextFile.txt�ļ����룬�������룬����ʾ�����
                int n = 0;  //n�����洢Ȩ�ز�Ϊ0�Ľ�������
                for(int i = 1;i < arr.size() - 1;i++){
                    if(arr[i] != 0){
                        n++;
                    }
                }
                Decode(HT,2 * n - 1);
                refresh();
                break;
            }
            case 6:{
                //��ӡ��������
                int n = 0;  //n�����洢Ȩ�ز�Ϊ0�Ľ�������
                for(int i = 1;i < arr.size() - 1;i++){
                    if(arr[i] != 0){
                        n++;
                    }
                }
                Traverse(HT,2 * n - 1);
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
