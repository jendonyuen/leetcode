// int [26] 用于字母 ‘a’ - ‘z’ 或 ‘A’ - ‘Z’
// int [128] 用于ASCII码
// int [256] 用于扩展ASCII码

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        auto beg = -1;
        vector<int> table(128, -1);

        for (int p = 0; p != s.size(); ++p) {
            beg = max(table[s[p]], beg);
            table[s[p]] = p;
            len = max(p - beg, len);
        }

        return len;
    }
};