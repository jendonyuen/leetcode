class Solution {
public:
    bool isPowerOfFour(int num) {
        // 防止-2147483648-1越界
        if (num < 1) return false;
        // 2^n=10000, 2^n - 1 = 01111
        // &按位与，两者为真才为真
        // 判断二进制num是否为100...形式组成，即一个1后面接n个0
        if (num & (num-1)) return false;
        // 判断1是否在奇数位，0x55555555(16进制)为1010101010101010101010101010101(二进制)
        if (num & 0x55555555) return true;
        return false;
    }
};