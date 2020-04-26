class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) {
            return true;
        }
        if (word[0] - 'Z' <= 0) {
            if (word[1] - 'Z' <= 0) {
                for (int i = 2; i < word.size(); ++i) {
                    if (word[i] - 'Z' > 0) return false;
                }
            } else {
                for (int i = 2; i < word.size(); ++i) {
                    if (word[i] - 'Z' <= 0) return false;
                }
            }
        } else {
            for (int i = 1; i < word.size(); ++i) {
                if (word[i] - 'Z' <= 0) return false;
            }
        }
        return true;
    }
};