class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int low = 0;
        int high = x;
        int ans = x / 2;
        while (true) {
            // cout << low << "," << ans << "," << high << endl;
            // 溢出检查
            if (ans > 46340) {
                high = ans;
                ans = (low + high) / 2;
                continue;
            } else if (ans * ans == x) {
                return ans;
            } else if (ans * ans < x) {
                // 先检查是否会溢出
                if (ans > 46339 || (ans+1) * (ans+1) > x) {
                    return ans;
                } else {
                    // (ans, high]
                    low = ans;
                    ans = (low + high) / 2;
                }
            } else {
                // (low, ans)
                high = ans;
                ans = (low + high) / 2;
            }
        }
        return 0;
    }
};