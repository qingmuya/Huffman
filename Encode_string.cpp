#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();
    ofstream outfile("TextFile.txt");
    transform(s.begin(), s.end(), s.begin(), ::tolower);//×ª»»´óÐ¡Ð´
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
