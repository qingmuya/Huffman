#include "menu.h"
using namespace std;
vector<double> Get_weight_char() {
    //���ļ����ұ����ַ�����s
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    // �ַ�ת��ΪСд
    vector<int> ch(30, 0);
    vector<double> pro;
    int sum = 0; // ��¼ÿ����ĸ�ܸ���
    for (int i = 1; i < 27; i++) {
        char n = 'a' + i-1;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }
    ch[27] = count(s.begin(),s.end(),',');
    ch[28] = count(s.begin(),s.end(),'.');
    ch[29] = count(s.begin(),s.end(),' ');
    sum = sum+ch[27]+ch[28]+ch[29];
    pro.push_back(sum);//���ܸ������������ĵ�һ��Ԫ����ʣ�µ��±�1-26������ĸ���ֵĸ���
    // ���������ĸ����
    for (int i = 1; i <= 29; i++) {
        pro.push_back(static_cast<double>(ch[i])/sum);
    }
    return pro;
}

