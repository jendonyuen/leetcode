// 扫描线, 栈
// 从左向右扫描
// 遇到加减号, 直接将之前的元素入栈
// 遇到乘除号, 下个元素与之栈顶元素相运算, 替换栈顶
// 将栈中元素相加

// 扫描线, 栈
// 从左向右扫描
// 遇到加减号, 直接将之前的元素入栈
// 遇到乘除号, 下个元素与之栈顶元素相运算, 替换栈顶
// 将栈中元素相加

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0;
        int sign = 1;
        char symbol = '+';  // 上个符号
        s.push_back('+');   // 加入哨兵

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + (s[i] - '0');
            } else if (s[i] == ' ') {
                continue;
            } else {
                if (symbol == '+') {
                stk.push(cur);
                } else if (symbol == '-') {
                    stk.push(-cur);
                } else if (symbol == '*') {
                    int t = stk.top() * cur;
                    stk.pop();
                    stk.push(t);
                } else if (symbol == '/') {
                    int t = stk.top() / cur;
                    stk.pop();
                    stk.push(t);
                }
                cur = 0;
                symbol = s[i];
            } 
        }

        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

/*
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int cur = 0;
        int sign = 1;
        char symbol = '+';

        auto push = [&symbol, &stk, &cur] () {
            if (symbol == '+') {
                stk.push(cur);
            } else if (symbol == '-') {
                stk.push(-cur);
            } else if (symbol == '*') {
                int t = stk.top() * cur;
                stk.pop();
                stk.push(t);
            } else if (symbol == '/') {
                int t = stk.top() / cur;
                stk.pop();
                stk.push(t);
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * 10 + (s[i] - '0');
            } else if (s[i] == ' ') {
                continue;
            } else {
                push();
                cur = 0;
                symbol = s[i];
            } 
        }
        push(); // 清理最后元素

        int res = 0;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
*/