class Solution {
    string decode(string &s, int &p) {
        if (p >= s.size()) {return "";}
        string res = "";
        int n = 0;
        for (; p < s.size(); p++) {
            if (s[p] >= '0' && s[p] <= '9') {
                n = n * 10 + s[p] - '0';
            } else if (s[p] == '[') {
                // 如果有括号就进入递归
                string t = decode(s, ++p);
                for (; n > 0; n--) {res += t;}
                n = 0;
            } else if (s[p] == ']') {
                // 遇到反括号则结束递归
                return res;
            } else {
                res.push_back(s[p]);
            }
        }
        return res;
    }
public:
    string decodeString(string s) {
        int p = 0;
        return decode(s, p);
    }
};