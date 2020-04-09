class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        vector<string> v;
        map<int, pair<int, int>> m;   // 还能放入的左括号剩余个数, 右括号剩余个数
        v.push_back("(");
        m[0] = make_pair(n - 1, 1);
        for (int i = 1; i != n * 2; ++i) {
            vector<string> vt;
            map<int, pair<int, int>> mt;
            for (auto &p: m) {
                if (p.second.first > 0) {
                    // 还能放入左括号
                    auto t = v[p.first];
                    t.push_back('(');
                    vt.push_back(t);
                    mt[int(vt.size() - 1)] = make_pair(p.second.first - 1, p.second.second + 1);
                } 
                if (p.second.second > 0) {
                    // 还能放入右括号
                    auto t = v[p.first];
                    t.push_back(')');
                    vt.push_back(t);
                    mt[int(vt.size() - 1)] = make_pair(p.second.first, p.second.second - 1);
                }
            }
            v = vt;
            m = mt;
        }
        return v;
    }


};