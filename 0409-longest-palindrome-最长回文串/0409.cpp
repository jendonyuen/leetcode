class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> table;
        for (auto &c : s) {
            if (table.find(c) != table.end()) {
                table[c] += 1;
            } else {
                table[c] = 1;
            }
        }
        int len = 0;
        int single = 0;
        bool hasSingle = false;
        for (auto &p : table) {
            single = p.second % 2;
            if (single == 1) {
                hasSingle = true;
            }
            if (p.second > 1) {
                len += p.second - single;
            } 
        }
        if (hasSingle) {
            len += 1;
        }
        return len;
    }
};