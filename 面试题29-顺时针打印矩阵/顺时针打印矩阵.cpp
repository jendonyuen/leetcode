class Solution {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    
    bool findNextCoords(vector<vector<int>>& path, int &x, int &y, int &di, int t = 3) {
        if (di > 3) di = 0;
        int nextY = y + directions[di][0];
        int nextX = x + directions[di][1];
        if (
            nextY == path.size() 
            || nextX == path[0].size() 
            || nextY == -1 
            || nextX == -1
            || path[nextY][nextX]
            ) {
            if (t == 0) return false;
            return findNextCoords(path, x, y, ++di, --t);
        }
        x = nextX;
        y = nextY;
        return true;
    }

    void search(vector<vector<int>>& matrix, vector<vector<int>>& path, int x, int y, int di) {
        res.push_back(matrix[y][x]);
        path[y][x] = 1;
        if (!findNextCoords(path, x, y, di)) return;
        search(matrix, path, x, y, di);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> row(matrix[0].size(), 0);
        vector<vector<int>> path(matrix.size(), row);
        search(matrix, path, 0, 0, 0);
        return res;
    }
};