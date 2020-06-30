class Solution {
    bool isInclude(string &child, string &parent) {
        if (child.size() >= parent.size()) return false;
        int p1 = 0;
        int p2 = 0;
        while(p2 < parent.size()) {
            if (p1 == child.size()) return true;
            if (child[p1] == parent[p2]) {
                p1++;
                p2++;
            } else {
                p2 -= p1 - 1;
                p1 = 0;
            }
        }
        return p1 == child.size();
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (auto &child: words) {
            for (auto &parent: words) {
                if (isInclude(child, parent)) {
                    res.push_back(child);
                    break;
                }
            }
        }
        return res;
    }
};


/* string::find()使用的是KMP算法, 速度更快
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (auto &child: words) {
            for (auto &parent: words) {
                if (child.size() < parent.size() and parent.find(child) != -1) {
                    res.push_back(child);
                    break;
                }
            }
        }
        return res;
    }
};
*/