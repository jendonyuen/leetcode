class Solution {
    inline int count(char& src, char& dst) {
        if (src > dst) {
            return 'z' - src + dst - 'a' + 1;
        } else {
            return dst - src;
        }
    }
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            // cout << s[i] << "to" << t[i] << count(s[i], t[i]) << endl;
            int c = count(s[i], t[i]);    // 计算当前需要改变的次数
            v[c]++;
        }
        int n = k / 26;
        int le = k % 26;
        for (int i = 1; i < v.size(); ++i) {
            int e = le - i >= 0 ? 1 : 0;
            // cout << i <<"~" << v[i] << ":" << n << "," << e << endl;
            if (v[i] > n + e) {
                return false;
            }
        }
        return true;
    }
};