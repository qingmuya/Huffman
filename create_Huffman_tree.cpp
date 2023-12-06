#include "menu.h"

using namespace std;

//创建哈夫曼树
void Create_Huffman_tree(vector<double> arr){
    /**
     * 尝试将向量中的值存入结构体数组中：即树的结点
    */

    //新建哈夫曼树
    HuffmanTree HT;
    //初始化
    int m = arr.size() * 2 - 1;
    HT = new HTNode[m + 1];
    for(int i = 1; i <= m ; ++i){
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    for(int i = 0;i < arr.size();i++){
        HT[i].ch = (char)('a' + i);
        HT[i].weight = arr[i + 1];
    }

    cout<<"char/tweiht"<<endl;
    for(int i = 0;i < arr.size();i++){
        cout<<HT[i].ch<<"/t"<<HT[i].weight<<endl;
    }


    // int m, s1, s2, i;
    // if (n <= 1){
    //     return;
    // }
    // m = 2 * n - 1;

    // //初始化
    // HT = new HTNode[m + 1];
    // for (i = 1; i <= m ; ++i){
    //     HT[i].parent = 0;
    //     HT[i].lchild = 0;
    //     HT[i].rchild = 0;
    // }

    // //录取叶子节点的权值
    // cout << "请输入叶子结点的权值：\n";
    // for (i = 1; i <= n; ++i){
    //     cin >> HT[i].weight;
    // }

    // /**
    //  * 最小生成树
    //  * 最终树的结点个数为m：要添加结点的数量*2-1  （ m = 2 * n - 1 ）
    // */
    // for (i = n + 1; i <= m; ++i){
    //     Select(HT, i - 1, s1, s2);
    //     HT[s1].parent = i;
    //     HT[s2].parent = i;
    //     HT[i].lchild = s1;
    //     HT[i].rchild = s2;
    //     HT[i].weight = HT[s1].weight + HT[s2].weight;
    // }


    // printf("weight  parent  lchild  rchild\n");
    // print(HT,m);
}

//补全课本中函数，返回两个最小权值
/*void Select(HuffmanTree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //赋一个较大的值，防止开始就被返回
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min1 && HT[i].parent == 0){
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    int zs = HT[s1].weight; //将原值存放起来，然后先赋予最大值，防止s1被重复选择
    HT[s1].weight = 0x3f3f3f3f;
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min2 && HT[i].parent == 0){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs;
}

//打印输出
void print(HuffmanTree HT,int n){
    for(int i = 1;i < n + 1;i++){
        printf("%d\t%d\t%d\t%d\n",HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }
}*/
