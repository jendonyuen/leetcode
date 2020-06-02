class Solution {
    int count = 0, m, n;
    inline bool canGoIn(int x, int y, int &k) {
        int t = 0;
        while(x > 0) {
            t += x % 10;
            x /= 10;
        }
        while(y > 0) {
            t += y % 10;
            y /= 10;
        }
        return t <= k;
    }
    void go(int x, int y, int &k, vector<vector<int>> &map) {
        if (x < n && y < m && map[y][x] == 0) {
            map[y][x] = 1;
            if (canGoIn(x, y, k)) {
                count++;
                // cout << x << "," << y << endl;
                go(x + 1, y, k, map);
                go(x, y + 1, k, map);
            }
        }
    }
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> map(m, vector<int>(n, 0));
        this->m = m;
        this->n = n;
        go(0, 0, k, map);
        return count;
    }
};