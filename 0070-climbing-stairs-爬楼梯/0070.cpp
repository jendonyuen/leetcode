class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n >= 3) {
            climb(n, 2, 1);
        }
        return num;
    }
private:
    int num = 1;
    void climb(int n, int a, int b) {
        num = a + b;
        if (n > 3) {
            climb(n - 1, num, a);
        }
    }
};