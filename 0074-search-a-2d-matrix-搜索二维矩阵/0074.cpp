class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int h = matrix.size();
        int w = matrix[0].size();
        if (w == 0) return false;
        
        int beg = 0;
        int end = h * w - 1;
        int mid;
        while(beg < end) {
            mid = (end + beg) / 2;
            int y = mid / w;
            int x = mid % w;
            if (matrix[y][x] >= target) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        return matrix[beg / w][beg % w] == target;
    }
};