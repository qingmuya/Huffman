#include "menu.h"

using namespace std;

//创建哈夫曼树
HuffmanTree Create_Huffman_tree(vector<double> arr){
    /**
     * 尝试将向量中的值存入结构体数组中：即树的结点
     * 剔除权重为0的结点
    */

    int n = arr.size() - 1;  //n用来存储结点的数量

    //新建哈夫曼树
    HuffmanTree HT;
    //初始化
    int m = n * 2 - 1,s1,s2;
    HT = new HTNode[m + 1];
    for(int i = 0; i <= m ; ++i){
        HT[i].parent = 0;
        HT[i].lchild = -1;
        HT[i].rchild = -1;
    }

    //字母的递增和元素序列的递增要分开控制
    int index_of_weight = 0;
    for(int i = 0;i < arr.size() - 4;i++){
        HT[index_of_weight].ch = (char)('a' + i);
        HT[index_of_weight].weight = arr[i + 1];
        index_of_weight++;
    }

    HT[26].ch = (char)(44);
    HT[26].weight = arr[27];
    HT[27].ch = (char)(46);
    HT[27].weight = arr[28];
    HT[28].ch = ' ';
    HT[28].weight = arr[29];

    /**
     * 最小生成树
     * 最终树的结点个数为m：要添加结点的数量*2-1  （ m = 2 * n - 1 ）
    */
    for (int i = n; i < m; ++i){
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].ch = '-';
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    HT[56].parent = -1;

    return HT;
}

//补全课本中函数，返回两个最小权值
void Select(HuffmanTree HT, int len, int &s1, int &s2){
    int i; //赋一个较大的值，防止开始就被返回
    double min1 = 100, min2 = 100;
    for (i = 0; i <= len; i++){
        if (HT[i].weight < min1 && HT[i].parent == 0){
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    double zs = HT[s1].weight; //将原值存放起来，然后先赋予最大值，防止s1被重复选择
    HT[s1].weight = 0x3f3f3f3f;
    for (i = 0; i <= len; i++){
        if(HT[i].weight < min2 && HT[i].parent == 0){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs;
}

//输出
void output(HuffmanTree HT,int n){
    ofstream outfile;
    outfile.open("HfmTree.txt");

    outfile<<"index"<<"\t"<<"char"<<"\t"<<"weight"<<"\t"<<"parent"<<"\t"<<"lchild"<<"\t"<<"rchild"<<endl;
    for(int i = 0;i < n;i++){
        outfile<<i<<"\t"<<HT[i].ch<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    outfile.close();
}
