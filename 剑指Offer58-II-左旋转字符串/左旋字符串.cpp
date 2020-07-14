class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        return s.substr(n, len - n) + s.substr(0, n);
    }
};