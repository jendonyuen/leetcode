class Solution {
    inline bool cut(string & magazine, char k) {
        for (int i = 0; i != magazine.size(); ++i) {
            if (magazine[i] == k) {
                magazine.erase(i, 1);
                return true;
            }
        }
        return false;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (auto &k : ransomNote) {
            bool isExist = cut(magazine, k);
            if (!isExist) return false;
        }
        return true;
    }
};