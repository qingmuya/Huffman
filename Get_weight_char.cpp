#include "menu.h"
using namespace std;
vector<double> Get_weight_char() {
    //打开文件并且保存字符串至s
    ifstream inputfile("file.txt");
    string s((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    inputfile.close();

    // 字母转换为小写
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    vector<int> ch(30, 0);
    vector<double> pro;
    int sum = 0; // 记录每个字母总个数
    //添加结点，也就是文本中会出现的符号
    for (int i = 1; i < 27; i++) {
        char n = 'a' + i-1;
        sum = sum + count(s.begin(), s.end(), n);
        ch[i] = count(s.begin(), s.end(), n);
    }
    ch[27] = count(s.begin(),s.end(),',');
    ch[28] = count(s.begin(),s.end(),'.');
    ch[29] = count(s.begin(),s.end(),' ');
    sum = sum+ch[27]+ch[28]+ch[29];
    pro.push_back(sum);//把总个数放入向量的第一个元素中剩下的下标1-26都是字母出现的概率
    // 计算各个字母概率
    for (int i = 1; i <= 29; i++) {
        pro.push_back(static_cast<double>(ch[i])/sum);
    }
    //返回每个字符的权重
    return pro;
}

