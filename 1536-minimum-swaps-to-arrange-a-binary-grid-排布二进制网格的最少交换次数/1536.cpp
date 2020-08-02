class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n, n);
        for (int y = 0; y < n; ++y) {
            for (int x = n-1; x > -1; --x) {
                if (grid[y][x]) {
                    v[y] = n - x - 1;
                    break;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] < n - i - 1) {
                bool b = false;
                for (int j = i + 1; j < n; ++j) {
                    if (v[j] >= n - i - 1) {
                        b = true;
                        for (int k = j; k > i; --k) {
                            swap(v[k], v[k-1]);
                            res++;
                        }
                        break;
                    }
                }
                if (!b) return -1;
            }
        }

        return res;
    }
};