// ref:
// https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/

// 入度表BFS, 拓扑排序
// 课程的入度为前置依赖的课程数量, 若入度为0则入队
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> coursePrerequistites(numCourses, 0);    // [后置课程] = [前置课程数量n]
        vector<vector<int>> table(numCourses);              // 邻接表: [前置课程] = [后置课程1, 后置课程2, ...]       
        queue<int> q;

        for (auto &pre: prerequisites) {
            coursePrerequistites[pre[0]]++;
            table[pre[1]].push_back(pre[0]);
        }
        
        for (int i = 0; i < coursePrerequistites.size(); ++i) {
            if (coursePrerequistites[i] == 0) {
                q.push(i);
                numCourses--;
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto &course: table[i]) {
                if (--coursePrerequistites[course] == 0) {
                    numCourses--;
                    q.push(course);
                }
            }
        }

        return numCourses == 0;

    }
};

// DFS,  0: 未搜索, 1: 正在搜索, -1: 搜索过
class Solution {
    vector<int> searched;
    vector<vector<int>> table;  // 邻接表: [前置课程] = [后置课程1, 后置课程2, ...]
    int n;
    bool dfs(int i) {
        if (searched[i] == 1) return false;
        if (searched[i] == -1) return true;
        searched[i] = 1;
        for (auto &a: table[i]) {
            if (!dfs(a)) return false;
        }
        searched[i] = -1;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        searched.resize(numCourses, 0); // 0: 未搜索, 1: 正在搜索, -1: 搜索过
        table.resize(numCourses);
        for (auto& a: prerequisites) {
            table[a[1]].push_back(a[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};


/* 超时
class Solution {
    vector<vector<int>> table;
    bool check(int i, unordered_set<int> searched) {
        if (table[i].empty()) return true;
        if (searched.find(i) != searched.end()) return false;
        searched.insert(i);
        for (auto &a: table[i]) {
            if (not check(a, searched)) return false;
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        table.resize(numCourses);

        for (auto &a: prerequisites) {
            table[a[0]].push_back(a[1]);
        }

        for (auto &a: table) {
            for (auto &course: a) {
                unordered_set<int> searched;
                if (not check(course, searched)) return false;
            }
        }
        return true;
    }
};
*/