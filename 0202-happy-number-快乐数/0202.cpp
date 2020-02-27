class Solution {
    int calc(int n) {
        int rtn = 0;
        while (n > 0) {
            int m = n % 10;
            rtn += m * m;
            n /= 10;
        }
        return rtn;
    }
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        while (fast != 1 || slow != 1) {
            // 慢指针计算一次
            slow = calc(slow);
            // 快指针计算两次
            fast = calc(fast);
            fast = calc(fast);
            // std::cout << fast << "," << slow << std::endl;
            if (fast == slow) {
                if (fast == 1) {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};