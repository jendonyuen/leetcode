class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        for(int i = 0; i != haystack.size(); ++i) {
            if (haystack[i] == needle[0]) {
                bool isFound = true;
                for (int j = 1; j != needle.size(); ++j) {
                    if (i + j >= haystack.size()) return -1;
                    if (haystack[i+j] != needle[j]) {
                        isFound = false;
                        break;
                    }
                }
                if (isFound) return i;
            }
        } 
        return -1;
    }
};