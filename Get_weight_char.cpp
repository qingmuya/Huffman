#include "menu.h"
using namespace std;
vector<double> Get_weight_char() {
    //���ļ����ұ����ַ�����s
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    // �ַ�ת��ΪСд
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<int> ch(27, 0);
    vector<double> pro;
    int sum = 0; // ��¼ÿ����ĸ�ܸ���
    for (int i = 1; i < 27; i++) {
        char n = 'a' + i-1;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }
    pro.push_back(sum);//���ܸ������������ĵ�һ��Ԫ����ʣ�µ��±�1-26������ĸ���ֵĸ���
    // ���������ĸ����
    for (int i = 1; i <= 26; i++) {
        pro.push_back(static_cast<double>(ch[i])/sum);
    }
    return pro;
}

