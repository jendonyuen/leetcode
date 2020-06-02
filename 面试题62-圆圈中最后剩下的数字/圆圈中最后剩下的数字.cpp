class Solution {
public:
    int lastRemaining(int n, int m) {
        // 最后一个人的安全位置为0
        // 反推上一轮该人所在位置
        int ans = 0;
        // 倒数第二轮有2个人
        for (int i = 2; i <= n; ++i) {
            ans = (ans + m) % i;
        }
        return ans;
    }
};