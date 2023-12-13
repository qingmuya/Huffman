#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();
    ofstream outfile("TextFile.txt");
    for (char c : s) {
        auto it = find(ch.begin(),ch.end(),c);
        int index = distance(ch.begin(),it);
        outfile<<HC[index+1];
        cout<<HC[index+1];
    }
    outfile.close();
}
