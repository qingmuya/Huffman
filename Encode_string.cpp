#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    //打开file.txt保存到s以方便之后操作
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();


    transform(s.begin(), s.end(), s.begin(), ::tolower);//把s英文字母都变成小写


    //打开TextFile.txt准备写入
    ofstream outfile("TextFile.txt");
    for (char c : s) {
        //定位c在ch中的位置，it类似于指针
        auto it = find(ch.begin(),ch.end(),c);
        //distance解指针，返回值是一个整数
        int index = distance(ch.begin(),it);
        outfile<<HC[index+1];
    }
    //加密完成后关闭文件
    outfile.close();


    //打开加密文本，设置要求显示在终端50行换行
    ifstream inputfile1("TextFile.txt");
    string s1((istreambuf_iterator<char>(inputfile1)), istreambuf_iterator<char>());
    inputfile1.close();
    int i = 0;
    for(char c:s1){
        cout<<s1[i++];
        if(i%50==0){
            cout<<endl;
        }
    }
}
