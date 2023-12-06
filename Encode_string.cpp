#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();
    ofstream outfile("TextFile.txt");
    transform(s.begin(), s.end(), s.begin(), ::tolower);//转换大小写
    for (char c : s) {
        if(c>='a' && c<='z'){
        auto it = find(ch.begin(),ch.end(),c);
        int index = distance(ch.begin(),it);
        outfile<<HC[index+1];
        }
        else{
            outfile<<c;
        }
    }
    outfile.close();
}
