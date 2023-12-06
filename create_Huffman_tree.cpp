#include "menu.h"

using namespace std;

//������������
HuffmanTree Create_Huffman_tree(vector<double> arr){
    /**
     * ���Խ������е�ֵ����ṹ�������У������Ľ��
     * �޳�Ȩ��Ϊ0�Ľ��
    */

    int n = 0;  //n�����洢Ȩ�ز�Ϊ0�Ľ�������
    for(int i = 1;i < arr.size() - 1;i++){
        if(arr[i] != 0){
            n++;
        }
    }

    //�½���������
    HuffmanTree HT;
    //��ʼ��
    int m = n * 2 - 1,s1,s2;
    HT = new HTNode[m + 1];
    for(int i = 1; i <= m ; ++i){
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    //��ĸ�ĵ�����Ԫ�����еĵ���Ҫ�ֿ�����
    int index_of_weight = 0;
    for(int i = 0;i < arr.size() - 1;i++){
        if(arr[i + 1] != 0){
            HT[index_of_weight].ch = (char)('a' + i);
            HT[index_of_weight].weight = arr[i + 1];
            index_of_weight++;
        }
    }

    /**
     * ��С������
     * �������Ľ�����Ϊm��Ҫ��ӽ�������*2-1  �� m = 2 * n - 1 ��
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

    return HT;
}

//��ȫ�α��к���������������СȨֵ
void Select(HuffmanTree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //��һ���ϴ��ֵ����ֹ��ʼ�ͱ�����
    for (i = 0; i <= len; i++){
        if (HT[i].weight < min1 && HT[i].parent == 0){
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    double zs = HT[s1].weight; //��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
    HT[s1].weight = 0x3f3f3f3f;
    for (i = 0; i <= len; i++){
        if (HT[i].weight < min2 && HT[i].parent == 0){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs;
}

//��ӡ���
void output(HuffmanTree HT,int n){
    ofstream outfile;
    outfile.open("HfmTree.txt");

    outfile<<"index"<<"\t"<<"char"<<"\t"<<"weight"<<"\t"<<"parent"<<"\t"<<"lchild"<<"\t"<<"rchile"<<endl;
    for(int i = 0;i < n;i++){
        outfile<<i<<"\t"<<HT[i].ch<<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t"<<HT[i].lchild<<"\t"<<HT[i].rchild<<endl;
    }
    outfile.close();
}
