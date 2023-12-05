#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

//������
void cal_len_huffman_tree(Huffmantree &HT){
    int n;
    printf("�������ַ�������\n");
    scanf("%d",&n);
    create_huffman_tree(HT,n);
    cal(HT,n);
}

//������������
void create_huffman_tree(Huffmantree &HT,int n){
    int m, s1, s2, i;
    if (n <= 1){
        return;
    }
    m = 2 * n - 1;
    HT = new Htnode[m + 1];
    for (i = 1; i <= m; ++i){
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    cout << "������Ҷ�ӽ���Ȩֵ��\n";
    for (i = 1; i <= n; ++i){
        cin >> HT[i].weight;
    }
    for (i = n + 1; i <= m; ++i){
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

//��ȫ�α��к���������������СȨֵ
void Select(Huffmantree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //��һ���ϴ��ֵ����ֹ��ʼ�ͱ�����
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min1 && HT[i].parent == 0){
            min1 = HT[i].weight;
            s1 = i;
        }
    }

    int zs = HT[s1].weight; //��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��

    HT[s1].weight = 100;
    for (i = 1; i <= len; i++){
        if (HT[i].weight < min2 && HT[i].parent == 0){
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs;
}

//���㲢���
void cal(Huffmantree HT,int n){
    int wpl = 0; //��Ȩ·������
    for(int i = 1;i <= n;i++){
        int Num_of_layers = 0;  //��������������������ĳ���
        int parent = HT[i].parent;
        int zs = i; //�м���������Ǽ�¼���
        while(parent != 0){
            zs = parent;
            parent = HT[zs].parent; //���Ÿ��׽��һֱ����
            Num_of_layers++;    //��������
        }
        wpl += HT[i].weight * Num_of_layers;
    }
    printf("WPL=%d\n",wpl);
}
