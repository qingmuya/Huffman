#include "menu.h"

void menu(){
    printf("\t*****欢迎使用以下功能****\n");
    printf("\t0：退出\n");
    printf("\t1：获取字符权重\n");
    printf("\t2：构建哈夫曼树\n");
    printf("\t3：哈夫曼编码\n");
    printf("\t4：加密\n");
    printf("\t4：译码\n");
    printf("\t4：打印哈夫曼树\n");
    printf("\t键入选项前数字调用功能：\n");
}

void Selectmenu(){
    while(1){
        int xz;
        scanf("%d",&xz);
        switch(xz){
            case 0:
                exit(1);
            case 1:{
                //获取字符权重：根据file.txt文件获取字符串权重
                vector<double> arr=Get_weight_char();
                cout<<"sum:"<<arr[0]<<endl;
                for(int i = 1;i<=26;i++){
                    cout<<(char)('a'+i-1)<<":"<<arr[i]<<endl;
                }
                refresh();
                break;
            }
            case 2:{
                //构建哈夫曼树：建立哈夫曼树并存于文件：HfmTree.txt
                //Create_Huffman_tree();
                refresh();
                break;
            }
            case 3:{
                //编码：根据HfmTree.txt求出每个字符的哈夫曼编码，然后将结果存入文件CodeFile.txt中。
                Encode_char();
                refresh();
                break;
            }
            case 4:{
                //加密：根据编码将file.txt文件加密，结果存于TextFile.txt
                Encode_string();
                refresh();
                break;
            }
            case 5:{
                //译码：读取TextFile.txt文件编码，进行译码，并显示结果。
                Decode();
                refresh();
                break;
            }
            case 6:{
                //打印哈夫曼树
                Print_Huffman_Tree();
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
