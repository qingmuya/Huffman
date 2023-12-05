#include "Cal_len_Huffman.h"
#include "create_Huffman_tree.h"
#include "print_Huffman_code.h"
#include "menu.h"

//������������
void create_huffmantree(HuffTree &HT,int n){
    int m, s1, s2, i;
    if (n <= 1){
        return;
    }
    m = 2 * n - 1;
    HT = new HTnode[m + 1];  //0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ�����
    for (i = 1; i <= m; ++i) //��1~m�ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }

    cout << "�������ַ���\n";
    for (i = 1; i <= n; ++i) //����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
        cin >> HT[i].data;


    cout << "������Ҷ�ӽ���Ȩֵ��\n";
    for (i = 1; i <= n; ++i) //����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
        cin >> HT[i].weight;
    for (i = n + 1; i <= m; ++i)
    { //ͨ��n-1�ε�ѡ��ɾ�����ϲ��������շ�����
        Select(HT, i - 1, s1, s2);
        //��HT[k](1��k��i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ��,
        // ������������HT�е����s1��s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
        HT[i].lchild = s1;
        HT[i].rchild = s2;                            //s1,s2�ֱ���Ϊi�����Һ���
        HT[i].weight = HT[s1].weight + HT[s2].weight; //i ��ȨֵΪ���Һ���Ȩֵ֮��
    }
}

//��ȫ�α��к���������������СȨֵ
void Select(HuffTree HT, int len, int &s1, int &s2){
    int i, min1 = 100, min2 = 100; //��һ���ϴ��ֵ����ֹ��ʼ�ͱ�����
    for (i = 1; i <= len; i++)
    {
        if (HT[i].weight < min1 && HT[i].parent == 0)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    int zs = HT[s1].weight; //��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
    HT[s1].weight = 100;
    for (i = 1; i <= len; i++)
    {
        if (HT[i].weight < min2 && HT[i].parent == 0)
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
    HT[s1].weight = zs; //�ָ�ԭ����ֵ
}

//�������������
void CreateHuffmanCode(HuffTree HT,HuffmanCode &HC,int n){
    int start;
    HC = new char*[n+1];
    char cd[n];
    cd[n-1] = '\0';
    for(int i = 1;i<=n;i++){
        start = n-1;
        int c = i;
        int f = HT[i].parent;
        while(f!=0){
            start--;
            if(HT[f].lchild ==c){
                cd[start] = '0';
            }
            else{
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
        cout<<HT[i].data<<":"<<HC[i]<<endl;
    }
}

//������
void print_huffman_code(HuffTree &HT){
    int n;
    printf("�������ַ�������\n");
    scanf("%d",&n);
    create_huffmantree(HT,n);
    HuffmanCode HC;
    CreateHuffmanCode(HT,HC,n);
}
