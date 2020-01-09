class Solution {
    //void 
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        if (row == 0 || col == 0) {
            return 1;
        }
        vector<vector<int>> hp = dungeon;
        for (int x = row - 1; x >= 0; --x) {
            for (int y = col - 1; y >=0; --y) {
                if (x == row - 1 && y == col - 1) {
                    hp[x][y] = max(1, 1 - dungeon[x][y]);
                } else if (x == row - 1) {
                    hp[x][y] = max(1, hp[x][y+1] - dungeon[x][y]);
                } else if (y == col - 1) {
                    hp[x][y] = max(1, hp[x+1][y] - dungeon[x][y]);
                } else {
                    int t = min(hp[x+1][y], hp[x][y+1]) - dungeon[x][y];
                    hp[x][y] = max(1, t);
                }
            }
        }
        return hp[0][0];
    }
};