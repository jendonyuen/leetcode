class Solution {
public:
    string addStrings(string num1, string num2) {
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
};