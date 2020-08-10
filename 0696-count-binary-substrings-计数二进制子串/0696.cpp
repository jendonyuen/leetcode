class Solution {
public:
    int countBinarySubstrings(string s) {
        char last = '*';
        int count = 0, lastCount = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != last) {
                res += min(lastCount, count);
                lastCount = count;
                last = s[i];
                count = 1;
            } else {
                count++;
            }
        }
        return res + min(lastCount, count);
    }
};


/*  统计的是不要求01组合在一起的
    int countBinarySubstrings(string s) {
        vector<int> v(s.size(), 0); // 统计1出现的次数
        int n1 = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            cout << "~~" << i << "~~" << endl;
            if (s[i] == '1') n1++;
            v[i] = n1;
            if (v[i] == float(i+1) / 2.0) {
                for (int k = 0; k <= i; ++k) cout << s[k]; cout << endl;
                res++;
            }
            for (int j = i - 1; j >= 0; --j) {
                if (v[i] - v[j] == float(i - j) / 2.0) {
                    for (int k = j + 1; k <= i; ++k) cout << s[k]; cout << endl;
                    res++;
                } 
            }
        }
        return res;
    }
*/