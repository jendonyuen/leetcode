class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return {{1}};
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<int> ranges = {n-1, n-1, 0, 1};
        int x = 0;
        int y = 0;
        int i = 1;
        int di = 0;
        while(res[y][x] == 0) {
            res[y][x] = i++;
            if (di == 0) {
                if (x < ranges[di]) {
                    x++;
                } else {
                    ranges[di]--;
                    di++;
                    y++;
                }
            } else if (di == 1) {
                if (y < ranges[di]) {
                    y++;
                } else {
                    ranges[di]--;
                    di++;
                    x--;
                }
            } else if (di == 2) {
                if (x > ranges[di]) {
                    x--;
                } else {
                    ranges[di]++;
                    di++;
                    y--;
                }
            } else if (di == 3) {
                if (y > ranges[di]) {
                    y--;
                } else {
                    ranges[di]++;
                    di = 0;
                    x++;
                }
            }
        }
        return res;
    }
};