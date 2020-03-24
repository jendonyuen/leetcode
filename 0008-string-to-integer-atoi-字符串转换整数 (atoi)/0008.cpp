class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        } 
        long long ans = 0;
        int symbol = +1;
        int i = 0;
        
        for (; i != str.size(); ++i) {
            if (str[i] == '-') {
            symbol = -1;
            break;
            } else if (str[i] == '+') {
                break;
            } else if (str[i] == ' ') {
                continue;
            } else if (str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + (str[i] - '0');
                break;
            } else {
                return 0;
            }
        }

        i++;
        for (; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + (str[i] - '0');
                if (symbol * ans > INT_MAX) {
                    return INT_MAX;
                }else if (symbol * ans < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                break;
            }
        }
        return symbol * ans;
    }
};