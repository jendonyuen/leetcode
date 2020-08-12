// 2020-08-13 每日一题
class Solution {
    // 字符串加法
    string addStrings(string& num1, string& num2) {
        int n = min(num1.size(), num2.size());
        int n1 = num1.size(), n2 = num2.size();
        string res;
        int carry = 0;
        for (int i = 0; i < n; ++i) {
            char cur = num1[n1-1-i] - '0' + num2[n2-1-i] + carry;
            carry = 0;
            if (cur > '9') {
                cur -= 10;
                carry = 1;
            }
            res.push_back(cur);
        }

        if (n1 < n2) {
            num1 = num2;
            n1 = n2;
        }
        for (int i = n1 - n - 1; i >= 0; --i) {
            char cur = num1[i] + carry;
            carry = 0;
            if (cur > '9') {
                cur -= 10;
                carry = 1;
            }
            res.push_back(cur);
        }
        if (carry > 0) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res = "0";
        res.reserve(220);
        int carry = 0, d = n2 - n1, times = 0;
        for (int j = n2 - 1; j >= 0; --j) {
            string cur;
            for (int i = n1 - 1; i >= 0; --i) {
                int t = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = 0;
                if (t >= 10) {
                    carry = t / 10;
                    t = t % 10;
                }
                cur.push_back(t + '0');
            }
            // 遍历剩余carry
            while (carry > 0) {
                int t = carry % 10;
                cur.push_back(t + '0');
                carry /= 10;
            }
            reverse(cur.begin(), cur.end());
            for (int i = 0; i < times; ++i) cur.push_back('0'); // 补0
            times++;
            res = addStrings(res, cur);      // 与之前结果相加
        }
        return res[0] == '0' ? "0" : res;
    }
};



/*
// old
class Solution {
    void sum(string &res, string &num) {
        // cout << res << "," << num << endl;
        int carry = 0;
        int i;
        for (i = 0; i < res.size(); ++i) {
            int t = res[res.size() - 1 - i] - '0' + num[num.size() - 1 - i] -'0' + carry;
            carry = 0;
            if(t >= 10) {
                carry = 1;
                t = t - 10;
            }
            res[res.size() - 1 - i] = t + '0';
        }
        for (; i < num.size(); ++i) {
            int t = num[num.size() - 1 - i] - '0' + carry;
            carry = 0;
            if(t >= 10) {
                carry = 1;
                t = t - 10;
            }
            res = to_string(t) + res;
        }
        if (carry > 0) {
            res = '1' + res;
        }
        // cout << "res:" << res << endl;
    }
public:
    string multiply(string num1, string num2) {
        string res = "0";
        int zeroNum = -1;
        for (int n2 = num2.size() - 1; n2 >= 0; n2--) {
            string s;
            zeroNum++;
            int carry = 0;
            for (int n1 = num1.size() - 1; n1 >= 0; n1--) {
                int a2 = num2[n2] - '0';
                int a1 = num1[n1] - '0';
                int r = a1 * a2 + carry;
                carry = 0;
                if (r >= 10) {
                    carry = r / 10;
                    r %= 10;
                } 
                s = to_string(r) + s;
            }
            if (carry > 0) {
                s = to_string(carry) + s;
            }
            for (int i = 0; i < zeroNum; ++i) {
                s.push_back('0');
            }
            sum(res, s);
        }
        if (res[0] == '0') return "0";
        return res;
    }
};
*/