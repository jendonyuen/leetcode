class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int t = n;
        int a = 0;
        while (t > 1) {
            a = t % 3;
            if (a != 0) return false;
            t /= 3;
        }
        return true;
    }
};