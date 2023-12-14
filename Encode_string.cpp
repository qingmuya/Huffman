#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    //打开file.txt保存到s
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();
    transform(s.begin(), s.end(), s.begin(), ::tolower);//转换大小写
    //打开TextFile.txt写入
    ofstream outfile("TextFile.txt");
    for (char c : s) {
        auto it = find(ch.begin(),ch.end(),c);
        int index = distance(ch.begin(),it);
        outfile<<HC[index+1];
    }
    outfile.close();

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
