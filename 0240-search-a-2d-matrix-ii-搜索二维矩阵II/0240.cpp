class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角遍历, 大于target舍弃列, 小于target舍弃行
        int ysize = matrix.size();
        if (!ysize) return false;
        int xsize = matrix[0].size();
        int y = 0, x = xsize - 1;
        while(x >= 0 && y < ysize) {
            if (matrix[y][x] == target) return true;
            if (matrix[y][x] < target) {
                y++;
            } else {
                x--;
            }
        }
        return false;
    }
};