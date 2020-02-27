#include <map>

class Solution {
    std::map<char, int> table;
public:
    bool isAnagram(string s, string t) {
        for (const auto &c: s) {
            if (table.find(c) == table.end()) {
                table[c] = 1;
            } else {
                table[c]++;
            }
        }
        for (const auto &c: t) {
            if (table.find(c) == table.end()) {
                return false;
            } else {
                table[c]--;
            }
        }
        for (const auto &n: table) {
            if (n.second != 0) {
                return false;
            }
        }
        return true;
    }
};