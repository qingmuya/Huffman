#include "menu.h"

HuffmanCode HC;//哈夫曼编码表
HuffmanTree HT =NULL;//哈夫曼树
vector<double> arr = Get_weight_char();
vector<char> ch;

void menu(){
    printf("\t**************欢迎使用以下功能***************\n");
    printf("\t*0：退出\n");
    printf("\t*1：获取字符权重\n");
    printf("\t*2：构建哈夫曼树\n");
    printf("\t*3：哈夫曼编码\n");
    printf("\t*4：加密\n");
    printf("\t*5：译码\n");
    printf("\t*6：打印哈夫曼树\n");
    printf("\t*键盘输入选项前数字来调用功能：\n");
}

BiTree set_tree(int i, int j,HuffmanTree HT){
    BiTree L;
    if(HT[i].lchild!=-1 && HT[i].rchild!=-1){
        j++;
        L=(BiTree)malloc(sizeof(BiTNode));//分配空间
        L->data = HT[i].weight;
        L->lchild = set_tree(HT[i].lchild, j, HT);
        L->rchild = set_tree(HT[i].rchild, j, HT);
    }
    else{
        j++;
        L=(BiTree)malloc(sizeof(BiTNode));//分配空间
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
                cout<<"退出成功"<<endl;
                exit(1);
            case 1:{
                //获取字符权重：根据file.txt文件获取字符串权重
                arr = Get_weight_char();
                cout<<"获取字符串权重成功"<<endl;
                cout<<"sum:"<<arr[0]<<endl;
                for(int i = 1;i<=26;i++){
                    cout<<(char)('a'+i-1)<<":"<<arr[i]<<endl;
                }
                cout<<','<<":"<<arr[27]<<endl;
                cout<<'.'<<":"<<arr[28]<<endl;
                cout<<"空格"<<":"<<arr[29]<<endl;
                refresh();
                break;
            }
            case 2:{
                //构建哈夫曼树：建立哈夫曼树并存于文件：HfmTree.txt
                HT = Create_Huffman_tree(arr);
                int n = 0;  //n用来存储权重不为0的结点的数量
                for(int i = 1;i < arr.size() - 1;i++){
                    if(arr[i] != 0){
                        n++;
                    }
                }
                output(HT,29 * 2 - 1);
                cout<<"已将哈夫曼树输出至文件：HfmTree.txt"<<endl;
                refresh();
                break;
            }
            case 3:{
                //编码：根据HfmTree.txt求出每个字符的哈夫曼编码，然后将结果存入文件CodeFile.txt中。
                Encode_char(arr,HC,HT,ch);
                cout<<"每个字符的哈夫曼编码已经生成至文件:CodeFile.txt"<<endl;
                refresh();
                break;
            }
            case 4:{
                //加密：根据编码将file.txt文件加密，结果存于TextFile.txt
                Encode_string(ch,HC);
                cout<<"加密后的短文已经生成至文件:TextFile.txt"<<endl;
                refresh();
                break;
            }
            case 5:{
                //译码：读取TextFile.txt文件编码，进行译码，并显示结果。
                Decode(HT,2 * 29 - 1);
                refresh();
                break;
            }
            case 6:{
                //打印哈夫曼树
                start(HT,56);
                refresh();
                break;
            }
            default:
                printf("输入非法字符，重新键入：\n");
                break;
        }
    }
}

//刷新函数
void refresh(){
    printf("\n");
    system("Pause");
    system("cls");
    menu();
}
