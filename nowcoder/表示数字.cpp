#include <iostream>
using namespace std;
class Solution {
public:
    string MarkNum(string s) {
        string res;
        bool bNum = false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!bNum) {
                    bNum = true;
                    res.push_back('*');
                }
                res.push_back(s[i]);
            } else {
                if (bNum) {
                    bNum = false;
                    res.push_back('*');
                }
                res.push_back(s[i]);
            }
        }
        if (s.back() >= '0' && s.back() <= '9') {
            res.push_back('*');
        }
        return res;
    }
};
 
 
int main() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        cout << solution.MarkNum(s) << endl;
    }
    return 0;
}


/*
https://www.nowcoder.com/questionTerminal/637062df51674de8ba464e792d1a0ac6
将一个字符中所有出现的数字前后加上符号“*”，其他字符保持不变
public static String MarkNum(String pInStr)
{

return null;
}
注意：输入数据可能有多行
*/