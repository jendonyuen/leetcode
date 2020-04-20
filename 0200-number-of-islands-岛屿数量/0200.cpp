class Solution {
    void search(vector<vector<char>>& v, int y, int x) {
        if (y >= v.size() || x >= v[0].size()) return;
        if (v[y][x] == '1') {
            v[y][x] = '2';   
            search(v, y - 1, x); 
            search(v, y + 1, x);
            search(v, y, x - 1);
            search(v, y, x + 1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;
        vector<vector<char>>& v = grid;
        int num = 0;
        for (int y = 0; y != v.size(); ++y) {
            for (int x = 0; x != v[0].size(); ++x) {
                if (v[y][x] == '1') {
                    num++;
                    search(v, y, x);
                }
            }
        }
        return num;
    }
};