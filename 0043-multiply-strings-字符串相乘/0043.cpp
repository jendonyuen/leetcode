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