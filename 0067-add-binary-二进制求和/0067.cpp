class Solution {
public:
    string addBinary(string a, string b) {
        bitset<10000> b1(a);
        bitset<10000> b2(b);
        auto res = b1;
        while(b2.any()) {
            auto t = b1;
            b1 = b1^b2;
            b2 = (t&b2) << 1;
            res = b1;
        }
        string s = res.to_string();
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') return s.substr(i, s.size() - i);
        }
        return "0";
    }
};