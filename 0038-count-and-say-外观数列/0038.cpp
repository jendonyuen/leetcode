class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            int n = 0;
            char t = s[0];
            for (auto c : s) {
                if (c == t) {
                    n++;
                } else {
                    temp += to_string(n);
                    temp.push_back(t);
                    t = c;
                    n = 1;
                }
            }
            temp += to_string(n);
            temp.push_back(t);
            s = temp;
        }
        return s;
    }
};