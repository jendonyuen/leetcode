class Solution {
    unordered_map<char, char> us;
    char findRoot(char c) {
        if (us.find(c) == us.end() || us[c] == c) {
            return c;
        }
        return findRoot(us[c]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (auto &eq: equations) {
            if (eq[1] == '=') {
                // cout << eq[0] << "==" << eq[3] << endl;
                us[findRoot(eq[0])] = findRoot(eq[3]);
            }
        }
        for (auto &eq: equations) {
            if (eq[1] == '!') {
                // cout << eq[0] << "!=" << eq[3] << endl;
                // cout << findRoot(eq[0]) << "?" << findRoot(eq[3]) << endl;
                if (findRoot(eq[0]) == findRoot(eq[3])) {
                    return false;
                }
            }
        }
        return true;
    }
};