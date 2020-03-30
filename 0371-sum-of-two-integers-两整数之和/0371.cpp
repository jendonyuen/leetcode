class Solution {
public:
    int getSum(int a, int b) {
        // &与       求进位
        // ^异或     无进位相加
        while (b != 0) {
            auto t = a ^ b;
            b = unsigned(a & b) << 1;
            a = t;
        }
        return a;
    }
};