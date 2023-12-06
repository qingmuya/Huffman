#include "menu.h"
using namespace std;

void Encode_char(vector<double> arr,HuffmanCode &HC,HuffmanTree HT,vector<char> &ch){
    int n = 0;  //n用来存储权重不为0的结点的数量
    for(int i = 1;i < arr.size() - 1;i++){
        if(arr[i] != 0){
            n++;
            ch.push_back('a'+i-1);
        }
    }
    HC = new char*[n+1];
    char cd[n];
    cd[n-1] = '\0';
    for(int i = 1;i<=n;i++){
        int start = n-1;
        int c = i;
        int f =  HT[i].parent;
        while (f!=0)
        {
            --start;
            if(HT[f].lchild == c) cd[start] = '0';
            else cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    ofstream outfile("CodeFile.txt");
    for(int i = 1;i<=ch.size();i++){
        outfile<<ch[i-1]<<":"<<HC[i]<<endl;
    }
    outfile.close();


}
