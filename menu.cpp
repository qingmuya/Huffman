#include "menu.h"

HuffmanCode HC;//�����������
HuffmanTree HT =NULL;//��������
vector<double> arr = Get_weight_char();
vector<char> ch;

void menu(){
    printf("\t**************��ӭʹ�����¹���***************\n");
    printf("\t*0���˳�\n");
    printf("\t*1����ȡ�ַ�Ȩ��\n");
    printf("\t*2��������������\n");
    printf("\t*3������������\n");
    printf("\t*4������\n");
    printf("\t*5������\n");
    printf("\t*6����ӡ��������\n");
    printf("\t*��������ѡ��ǰ���������ù��ܣ�\n");
}

BiTree set_tree(int i, int j,HuffmanTree HT){
    BiTree L;
    if(HT[i].lchild!=-1 && HT[i].rchild!=-1){
        j++;
        L=(BiTree)malloc(sizeof(BiTNode));//����ռ�
        L->data = HT[i].weight;
        L->lchild = set_tree(HT[i].lchild, j, HT);
        L->rchild = set_tree(HT[i].rchild, j, HT);
    }
    else{
        j++;
        L=(BiTree)malloc(sizeof(BiTNode));//����ռ�
        L->data = HT[i].weight;
        L->lchild = NULL;
        L->rchild = NULL;
    }
    return L;
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
                cout<<"sum:"<<arr[0]<<endl;
                for(int i = 1;i<=26;i++){
                    cout<<(char)('a'+i-1)<<":"<<arr[i]<<endl;
                }
                cout<<','<<":"<<arr[27]<<endl;
                cout<<'.'<<":"<<arr[28]<<endl;
                cout<<"�ո�"<<":"<<arr[29]<<endl;
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
                output(HT,29 * 2 - 1);
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
                Decode(HT,2 * 29 - 1);
                refresh();
                break;
            }
            case 6:{
                //��ӡ��������
                start(HT,56);
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
