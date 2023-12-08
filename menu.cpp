#include "menu.h"

HuffmanCode HC;//�����������
HuffmanTree HT =NULL;//��������
vector<double> arr = Get_weight_char();
vector<char> ch;

void menu(){
    cout<<"\t*****��ӭʹ�����¹���****"<<endl;
    cout<<"\t1����ȡ�ַ�Ȩ��"<<endl;
    cout<<"\t2��������������"<<endl;
    cout<<"\t3������������"<<endl;
    cout<<"\t4������"<<endl;
    cout<<"\t5������"<<endl;
    cout<<"\t6����ӡ��������"<<endl;
    cout<<"\t0���˳�"<<endl;
    cout<<"\t��������ѡ��ǰ���������ù��ܣ�"<<endl;
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
                Traverse(HT,29 * 2 - 1);
                refresh();
                break;
            }
            default:
                printf("����Ƿ��ַ������¼��룺\n");
                break;
            /***
             * δ������ĸ ����������
             *
            */
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
