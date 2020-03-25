class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        int totalSurfaces = 0;
        for (int y = 0; y != grid.size(); ++y) {
            for (int x = 0; x != grid.size(); ++x) {
                int surfaces = 0;
                if (grid[y][x] > 0) surfaces = grid[y][x] * 4 + 2;
                else continue;
                // cout << surfaces << ",";
                if (x > 0) {
                    surfaces -= min(grid[y][x], grid[y][x-1]) * 2;
                }
                // cout << surfaces << ",";
                if (y > 0) {
                    surfaces -= min(grid[y][x], grid[y-1][x]) * 2;
                }
                // cout << surfaces << endl;
                totalSurfaces += surfaces;
            }
        }
        return totalSurfaces;
    }
};