class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        bool isFinished = false;
        while (!isFinished) {
            isFinished = true;
            for (int y = 0; y < ans.size(); ++y) {
                for (int x = 0; x < ans[0].size(); ++x) {
                    if (ans[y][x] == 0) continue;
                    int minD = INT_MAX;
                    if (y > 0) {
                        minD = ans[y-1][x] + 1 < minD ? ans[y-1][x] + 1 : minD;
                    }
                    if (x > 0) {
                        minD = ans[y][x-1] + 1 < minD ? ans[y][x-1] + 1 : minD;
                    }
                    if (y < ans.size() - 1) {
                        minD = ans[y+1][x] + 1 < minD ? ans[y+1][x] + 1: minD;
                    }
                    if (x < ans[0].size() - 1) {
                        minD = ans[y][x+1] + 1 < minD ? ans[y][x+1] + 1: minD;
                    }
                    if (minD != ans[y][x]) {
                        ans[y][x] = minD;
                        isFinished = false;
                    }
                }
            }
        }
        return ans;
    }
};