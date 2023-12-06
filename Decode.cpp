#include "menu.h"
#include <windows.h>

using namespace std;

void Decode(HuffmanTree HT,int m){
    //stream�����������ʹ�ã���ȡ�ļ�����
    ifstream inputfile("Textfile.txt");
    vector<char> data((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    /**
     * ���������ݽ����и�ӽ����õĹ���������Ѱַ��
     * ֻҪĳ�ڵ���һ�����ӽ��Ϊ��������ýڵ��ֵ
    */

    while(!(data.empty())){
        int index = m - 1;
        while(1){
            char next_direction = data.front();    //������һ������
            //���Ϊ0��Ѱ�����ӣ�Ϊ1Ѱ���Һ���
            if(next_direction == '0'){
                if(HT[index].lchild == NULL){
                    cout<<HT[index - 1].ch;
                    break;
                }
                index = HT[index].lchild;   //ָ����
            }else{
                if(HT[index].rchild == NULL){
                    //data.push_front(index);
                    cout<<HT[index - 1].ch;
                    break;
                }
                index = HT[index].rchild;   //ָ����
            }
            data.erase(data.begin());
        }
    }
}
