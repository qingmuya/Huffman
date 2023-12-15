#include "menu.h"
using namespace std;

void Encode_char(vector<double> arr,HuffmanCode &HC,HuffmanTree HT,vector<char> &ch){
    //把26个小写英文字母和标点符号加到ch里面，对ch初始化
    for(int i = 1;i <= 26;i++){
        ch.push_back('a'+i-1);
    }
    ch.push_back(',');
    ch.push_back('.');
    ch.push_back(' ');
    int n = ch.size();
    HC = new char*[n+1];
    char cd[n];
    cd[n-1] = '\0';
    for(int i = 1;i<=n;i++){
        int start = n-1;
        int c = i-1;
        int f =  HT[i-1].parent;//f作为当前结点的双亲结点下标
        while (f!=0){
            --start;
            if(HT[f].lchild == c) cd[start] = '0';
            else cd[start] = '1';
            //更新c和f的值实现回溯
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    //打开文件CodeFile.txt
    ofstream outfile("CodeFile.txt");
    for(int i = 1;i<=ch.size();i++){
        //把字符编码输出到终端和文件里面
        cout<<ch[i-1]<<":"<<HC[i]<<endl;
        outfile<<ch[i-1]<<":"<<HC[i]<<endl;
    }
    //关闭文件
    outfile.close();
}
