// 位运算
// ref:https://leetcode-cn.com/problems/gray-code/solution/ge-lei-bian-ma-ji-jian-di-gui-fa-by-zoffer/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        for (int i = 1; i <= n; ++i) {
            for (int j = res.size() - 1; j >= 0; --j) {
                // 将1左移i-1位得到 100... 和 xx...做与运算
                int cur = res[j] | 1 << (i - 1);    
                res.push_back(cur);
            }
        }
        return res;
    }
};

// old
class Solution {
    int binaryStringToInt(string &s) {
        int res = 0;
        int n = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] - '0') {
                res += pow(2, n);
            }
            n++;
        }
        return res;
    }
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        string s;
        unordered_set<string> us;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            s.push_back('0');
        }
        res.push_back(0);
        us.insert(s);
        // cout << s << ": " << binaryStringToInt(s) << endl;

        while(res.size() < pow(2, n)) {
            for (int i = n-1; i >= 0; --i) {
                string t = s;
                if (t[i] == '0') {
                    t[i] += 1;
                } else {
                    t[i] -= 1;
                }
                if (us.find(t) == us.end()) {
                    int ti = binaryStringToInt(t);
                    // cout << t << ": " << ti << endl;
                    us.insert(t);
                    res.push_back(ti);
                    s = t;
                    break;
                }
            }
        }
        return res;
    }
};