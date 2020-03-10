class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int act[N] = {0}; // 该人act[i] 相信的人的数量
        int pas[N] = {0}; // 该人act[i] 被多少人相信

        for(auto &p: trust) {
            act[p[0] - 1] += 1;
            pas[p[1] - 1] += 1;
        }

        for(int i = 0; i != N; ++i) {
            if (act[i] == 0 && pas[i] == N - 1) return i + 1;
        }
        return -1;
    }
};