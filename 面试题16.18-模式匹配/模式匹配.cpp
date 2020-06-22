class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if (pattern.empty() && value.empty()) return true;
        if (pattern.empty()) return false;
        if (value.empty()) {
            if (pattern.find('a') != pattern.npos && pattern.find('b') != pattern.npos) {
                return false;
            } else {
                return true;
            }
        }
        int aCount = 0;
        int bCount = 0;
        for (auto &c : pattern) {
            if (c == 'a') {
                aCount++;
            } else {
                bCount++;
            }
        }

        int la = 0;
        int lb = 0;
        if (aCount) la = int(value.size()) / aCount;
        if (bCount) lb = int(value.size()) / bCount;

        for (int i = 0; i <= la; ++i) {
            for (int j = 0; j <= lb; ++j) {
                if (i * aCount + j * bCount == value.size()) {
                    string sa = "#";
                    string sb = "#";
                    int k = 0;
                    for (auto &c: pattern) {
                        if (c == 'a') {
                            if (sa == "#") sa = value.substr(k, i);
                            else if (sa != value.substr(k, i)) break;
                            k += i;
                        } else {
                            if (sb == "#") sb = value.substr(k, j);
                            else if (sb != value.substr(k, j)) break;
                            k += j;
                        }
                    }
                    if (k == value.size()) return true;
                }
            }
        }
        return false;
    }
};