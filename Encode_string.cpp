#include "menu.h"

using namespace std;

void Encode_string(vector<char> ch,HuffmanCode HC){
    //��file.txt���浽s�Է���֮�����
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();


    transform(s.begin(), s.end(), s.begin(), ::tolower);//��sӢ����ĸ�����Сд


    //��TextFile.txt׼��д��
    ofstream outfile("TextFile.txt");
    for (char c : s) {
        //��λc��ch�е�λ�ã�it������ָ��
        auto it = find(ch.begin(),ch.end(),c);
        //distance��ָ�룬����ֵ��һ������
        int index = distance(ch.begin(),it);
        outfile<<HC[index+1];
    }
    //������ɺ�ر��ļ�
    outfile.close();


    //�򿪼����ı�������Ҫ����ʾ���ն�50�л���
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
