class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int cur;
        for (auto& a: tokens) {
            if (a == "+") {
                int t = stk.top();
                stk.pop();
                t += cur;
                cur = t;
            } else if (a == "-") {
                int t = stk.top();
                stk.pop();
                t -= cur;
                cur = t;
            } else if (a == "*") {
                int t = stk.top();
                stk.pop();
                t *= cur;
                cur = t;
            } else if (a == "/") {
                int t = stk.top();
                stk.pop();
                t /= cur;
                cur = t;
            } else {
                stk.push(cur);
                cur = stoi(a);
            }
        }
        return cur;
    }
};