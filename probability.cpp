#include "set.h"
vector<double> probability() {
    ifstream inputfile("file.txt");
    string s(istreambuf_iterator<char>(inputfile), istreambuf_iterator<char>());
    inputfile.close();
    transform(s.begin(), s.end(), s.begin(), ::tolower); // 全部变成小写
    vector<int> ch(26, 0);
    vector<double> pro;
    int sum = 0; // 记录每个字母总个数

    for (int i = 0; i < 26; i++) {
        char n = 97 + i;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }

    // 计算各个字母概率
    for (int i = 0; i < 26; i++) {
        pro.push_back(static_cast<double>(ch[i]) / sum);
    }

    return pro;
}
