class Solution {
public:
    int divide(int dividend, int divisor) {
        // 判断边界情况
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } else if (divisor == 1) {
                return INT_MIN;
            }
        }

        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else return 0;
        }

        int res = 0;
        if (dividend == INT_MIN) {
            if (divisor > 0) {
                dividend += divisor;
            } else {
                dividend -= divisor;
            }
            res++;
        }

        // 全改为正数进行计算
        int symbol = 1;
        if (dividend < 0) {
            symbol = -symbol;
            dividend = -dividend;
        } 
        if (divisor < 0) {
            symbol = -symbol;
            divisor = -divisor;
        }

        // 将除数移位到比被除数大
        int count = 0;
        bool overflow = false;
        while(dividend >= divisor) {
            if (divisor >= INT_MAX >> 1) {
                overflow = true;
                count++;
                break;
            }
            divisor = divisor << 1;
            count++;
        }

        // 进行移位相减, 模拟列竖式算除法
        while(count > 0) {
            if (overflow) {
                overflow = false;
            } else {
                divisor = divisor >> 1;
            }
            count--;
            if (dividend >= divisor) {
                res += 1 << count;
                dividend -= divisor;
            }
        }
        if (symbol == -1) return -res;
        return res;
    }
};