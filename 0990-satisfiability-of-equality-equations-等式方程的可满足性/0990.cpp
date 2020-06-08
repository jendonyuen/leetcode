// 并查集 按秩合并
class Solution {
    unordered_map<char, char> us;
    unordered_map<char, int> rank;
    char findRoot(char c) {
        if (us.find(c) == us.end() || us[c] == c) {
            return c;
        }
        return findRoot(us[c]);
    }
    int getRank(char root) {
        if(rank.find(root) == rank.end()) {
            return 0;
        } 
        return rank[root];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (auto &eq: equations) {
            if (eq[1] == '=') {
                char rootLeft = findRoot(eq[0]);
                char rootRight = findRoot(eq[3]);
                int rankLeft = getRank(rootLeft);
                int rankRight = getRank(rootRight);
                // 按秩合并
                if (rankLeft > rankRight) {
                    us[rootRight] = rootLeft;
                } else if (rankLeft < rankRight) {
                    us[rootLeft] = rootRight;
                } else {
                    us[rootLeft] = rootRight;
                    rank[rootRight]++;
                }
            }
        }
        for (auto &eq: equations) {
            if (eq[1] == '!') {
                if (findRoot(eq[0]) == findRoot(eq[3])) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
// 并查集
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
                us[findRoot(eq[0])] = findRoot(eq[3]);
            }
        }
        for (auto &eq: equations) {
            if (eq[1] == '!') {
                if (findRoot(eq[0]) == findRoot(eq[3])) {
                    return false;
                }
            }
        }
        return true;
    }
};
*/