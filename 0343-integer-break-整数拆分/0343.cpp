class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        // 剩下的可被2整分的情况下, 分解为尽可能多的3
        // (1+3 分解为 2+2)
        int res = 1;
        while((n - 3) >= 0 && n - 3 != 1) {
            res *= 3;
            n -= 3;
            // cout << "3,";
        }
        while(n-2 >= 0) {
            res *= 2;
            n -= 2;
            // cout << "2,";
        }
        // cout << endl;
        return res;
    }
};