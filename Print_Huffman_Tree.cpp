#include "menu.h"

using namespace std;

// ����״�ṹ�����������
void printHuffmanTree(HuffmanTree tree, int root, int level) {
    ofstream outfile;
    outfile.open("TreePrint.txt",ios::app);
    if (root != -1) {
        // ���������
        printHuffmanTree(tree, tree[root].rchild, level + 1);

        // �����ǰ�ڵ�
        cout<<setw(4 * level)<<""; // ��������
        cout<<tree[root].ch <<" ("<<tree[root].weight<<")"<<endl;

        outfile<<setw(4 * level)<<""; // ��������
        outfile<<tree[root].ch <<" ("<<tree[root].weight<<")"<<endl;

        // ���������
        printHuffmanTree(tree, tree[root].lchild, level + 1);
    }
    outfile.close();
}
