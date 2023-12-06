#include "set.h"
vector<double> probability() {
    ifstream inputfile("file.txt");
    string s(istreambuf_iterator<char>(inputfile), istreambuf_iterator<char>());
    inputfile.close();
    transform(s.begin(), s.end(), s.begin(), ::tolower); // ȫ�����Сд
    vector<int> ch(26, 0);
    vector<double> pro;
    int sum = 0; // ��¼ÿ����ĸ�ܸ���

    for (int i = 0; i < 26; i++) {
        char n = 97 + i;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }

    // ���������ĸ����
    for (int i = 0; i < 26; i++) {
        pro.push_back(static_cast<double>(ch[i]) / sum);
    }

    return pro;
}
