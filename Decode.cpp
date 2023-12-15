#include "menu.h"
#include <windows.h>

using namespace std;


void Decode(HuffmanTree HT,int m){
    //stream流和向量结合使用，读取文件内容
    ifstream inputfile("Textfile.txt");
    vector<char> data((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    /**
     * 对向量内容进行切割，从建立好的哈夫曼树中寻址。
     * 只要某节点下一个孩子结点为空则输出该节点的值
    */

    while(!(data.empty())){
        int index = m - 1;
        while(1){
            char next_direction = data.front();    //代表下一个方向
            //如果为0则寻找左孩子，为1寻找右孩子
            if(next_direction == '0'){
                if(HT[index].lchild == -1){
                    cout<<HT[index].ch;
                    break;
                }
                index = HT[index].lchild;   //指向结点
            }else{
                if(HT[index].rchild == -1){
                    //cout<<HT[index].ch;
                    cout<<HT[index].ch;
                    break;
                }
                index = HT[index].rchild;   //指向结点
            }
            data.erase(data.begin());
        }
    }
}
