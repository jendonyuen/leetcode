class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long t = 1;
        int p = 0;
        while (t < n) {
            p++;
            t = pow(5, p);
        }
        for(;p > 0;p--) {
            ans += n / pow(5, p);
        }
        return ans;
    }
};