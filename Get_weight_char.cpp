#include "menu.h"
using namespace std;
vector<double> Get_weight_char() {
    //打开文件并且保存字符串至s
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    // 字符转换为小写
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<int> ch(27, 0);
    vector<double> pro;
    int sum = 0; // 记录每个字母总个数
    for (int i = 1; i < 27; i++) {
        char n = 'a' + i-1;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }
    pro.push_back(sum);//把总个数放入向量的第一个元素中剩下的下标1-26都是字母出现的概率
    // 计算各个字母概率
    for (int i = 1; i <= 26; i++) {
        pro.push_back(static_cast<double>(ch[i])/sum);
    }
    return pro;
}

