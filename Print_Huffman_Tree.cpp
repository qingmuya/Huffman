#include "menu.h"

using namespace std;

// 以树状结构输出哈夫曼树
void printHuffmanTree(HuffmanTree tree, int root, int level) {
    ofstream outfile;
    outfile.open("TreePrint.txt",ios::app);
    if (root != -1) {
        // 输出右子树
        printHuffmanTree(tree, tree[root].rchild, level + 1);

        // 输出当前节点
        cout<<setw(4 * level)<<""; // 控制缩进
        cout<<tree[root].ch <<" ("<<tree[root].weight<<")"<<endl;

        outfile<<setw(4 * level)<<""; // 控制缩进
        outfile<<tree[root].ch <<" ("<<tree[root].weight<<")"<<endl;

        // 输出左子树
        printHuffmanTree(tree, tree[root].lchild, level + 1);
    }
    outfile.close();
}
