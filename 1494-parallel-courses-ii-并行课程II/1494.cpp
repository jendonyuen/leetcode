// 第 29 场双周赛

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first < p2.first;
}

class Solution {
    vector<int> learned;
    unordered_set<int> learning;
    vector<unordered_set<int>> table;
    int res = 0, m, t = 0, k;
    bool search(int i) {
        if (learning.find(i) != learning.end()) return false;
        if (learned[i]) return true;
        for (auto &j: table[i]) {
            if (not learned[j]) {
                return false;
            }
        }
        m--;
        t++;
        learning.insert(i);
        return true;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        table.resize(n);
        learned.resize(n, 0);
        this->m = n;
        this->k = k;
        for (auto &dp : dependencies) {
            table[dp[1]-1].insert(dp[0] - 1);
        }
        
        while(m > 0) {
            // for (auto a : learned) cout << a << ","; cout << endl;
            res++;
            t = 0;  // 当前在学习的课程数
            for (auto &ln: learning) {
                learned[ln] = 1;
            }
            learning = {};
            vector<pair<int, int>> toLearn;
            for (int i = 0; i < n; ++i) {
                int futureNum = 0;
                for (auto &j : table[i]) {
                    if (not learned[j]) futureNum++; 
                }
                if (futureNum > 0) {
                    toLearn.push_back(make_pair(futureNum, i));
                } else {
                    if (not learned[i]) toLearn.push_back(make_pair(n, i));
                }
            }
            
            sort(toLearn.begin(), toLearn.end(), cmp);
            // for (auto &a: toLearn) cout << a.first << "," << a.second << "  "; cout << endl;
            for (auto &a: toLearn) {
                for (auto &b: table[a.second]) {
                    if (t == k) break;
                    search(b);
                }
            }    
            for (auto &a: toLearn) {
                if (t == k) break;
                search(a.second);
            }
        }
        
        return res;
    }
};



/* 比赛时代码
class Solution {
    vector<int> learned;
    unordered_set<int> learning;
    vector<unordered_set<int>> table;
    int res = 0, m, t = 0, k;
    bool search(int i) {
        if (learning.find(i) != learning.end()) return false;
        if (learned[i]) return true;
        for (auto &j: table[i]) {
            if (not learned[j]) {
                return false;
            }
        }
        m--;
        t++;
        learning.insert(i);
        return true;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        table.resize(n);
        learned.resize(n, 0);
        this->m = n;
        this->k = k;
        for (auto &dp : dependencies) {
            table[dp[1]-1].insert(dp[0] - 1);
        }
        
        while(m > 0) {
            // for (auto a : learned) cout << a << ","; cout << endl;
            res++;
            t = 0;  // 当前在学习的课程数
            for (auto &ln: learning) {
                learned[ln] = 1;
            }
            learning = {};
            
            // vector<vector<int>> toLearn(n);
            for (int i = 0; i < n; ++i) {
                int futureNum = 0;
                for (auto &j : table[i]) {
                    if (not learned[j]) futureNum++; 
                }
                if (futureNum == 1) {
                    if (t == k) break;
                    for (auto &j : table[i]) {
                        if (t == k) break;
                        search(j);
                    }
                }
            }
            
            for (int i = 0; i < n; ++i) {
                int futureNum = 0;
                for (auto &j : table[i]) {
                    if (not learned[j]) futureNum++; 
                }
                if (futureNum == 2) {
                    if (t == k) break;
                    for (auto &j : table[i]) {
                        if (t == k) break;
                        search(j);
                    }
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if (t == k) break;
                search(i);
            }
        }
        
        return res;
    }
};
*/