class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> coordsRange;
        coordsRange.push_back(matrix[0].size() - 1);
        coordsRange.push_back(matrix.size() - 1);
        coordsRange.push_back(0);
        coordsRange.push_back(1);
        vector<int> res;

        int y = 0;
        int x = 0;
        int di = 0;
        int sz = matrix.size() * matrix[0].size();
        while (true) {
            res.push_back(matrix[y][x]);
            if (res.size() == sz) break;
            int nextY = y + directions[di][0];
            int nextX = x + directions[di][1];
            if (di == 0) {
                if (nextX > coordsRange[di]) {
                    coordsRange[di]--;
                    di++;
                    nextY = y + directions[di][0];
                    nextX = x + directions[di][1];
                }
            } else if (di == 1) {
                if (nextY > coordsRange[di]) {
                    coordsRange[di]--;
                    di++;
                    nextY = y + directions[di][0];
                    nextX = x + directions[di][1];
                }
            } else if (di == 2) {
                if (nextX < coordsRange[di]) {
                    coordsRange[di]++;
                    di++;
                    nextY = y + directions[di][0];
                    nextX = x + directions[di][1];
                }
            } else if (di == 3) {
                if (nextY < coordsRange[di]) {
                    coordsRange[di]++;
                    di = 0;
                    nextY = y + directions[di][0];
                    nextX = x + directions[di][1];
                }
            }
            y = nextY;
            x = nextX;
        }
        return res;
    }
};