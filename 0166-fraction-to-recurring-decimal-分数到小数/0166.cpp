class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "denominator == 0";
        if (numerator == 0) return "0";
        string res;

        if ((numerator < 0) ^ (denominator < 0)) res = "-";
        long long num = abs(numerator);
        long long dnm = abs(denominator); 

        if (num > dnm) {
            res += to_string(num / dnm);
            num = num % dnm;
        } 
        if (res.empty()) res = "0";
        if (res == "-") res.push_back('0');
        if (num > 0) res.push_back('.');

        unordered_map<int, int> remainders;
        int i = res.size();
        remainders[num] = i;
        while (num > 0) {
            num *= 10;
            int rm = num % dnm;
            res.push_back('0' + num / dnm);
            num = rm;
            if (rm == 0) {
                break;
            } else if (remainders.count(rm)) {
                int j = remainders[rm];
                int n = res.size();
                res.insert(j, "(");
                res.push_back(')');
                break;
            }
            remainders[rm] = ++i;
        }

        return res;
    }
};

/*
3123214
5432
*/