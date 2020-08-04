// ref:
// https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/

// 2020-08-04 每日一题-重做拓扑排序, 排序结果可参考第210题
class Solution {
public:
    // 拓扑排序: 前置依赖课程数为0(入度为0)的课程入队
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseReq(numCourses, 0);   // 统计每门课的前置依赖课程数
        vector<vector<int>> table(numCourses);  // 邻接表 [前置课程] = [后置课程1, 后置课程2, ...]
        
        // 构建两个表
        for (auto &pre: prerequisites) {
            courseReq[pre[0]]++;
            table[pre[1]].push_back(pre[0]);
        }

        queue<int> que;
        // 遍历courseReq, 将前置课程数为0(入度为0)的课程入队
        for (int i = 0; i < courseReq.size(); ++i) {
            if (courseReq[i] == 0) {
                que.push(i);
                numCourses--;
            }
        }

        // 将队内元素(课程)弹出, 搜索对应邻接表, 将新的入度为0的元素(前置课程数为0的课程)入队
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            for (auto &course: table[i]) {
                if (--courseReq[course] == 0) {
                    que.push(course);
                    numCourses--;
                }
            }
        }

        return numCourses == 0;
    }
};

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