// 双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        int p = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (p >= s.size()) return true;
            if (s[p] == t[i]) ++p;
        }
        return p >= s.size();
    }
};


// 进阶: 若t不变, 大量比较s, 可动态规划, 存储字符下次出现的位置
class Solution {
    vector<vector<int>> v;
    void build(string &parent) {
        v.resize(parent.size() + 1, vector<int>(128, -1));
        for (int i = 0; i < parent.size(); ++i) {
            int k = parent[i];
            for (int j = i; j >= 0; --j) {
                if (v[j][k] > 0) break;
                v[j][k] = i+1;
            }
        }
    }
    bool check(string &s) {
        int p = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (v[p][s[i]] < 0) return false;
            p = v[p][s[i]];
        }
        return true;
    }
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) return false;
        build(t);
        return check(s);
    }
};