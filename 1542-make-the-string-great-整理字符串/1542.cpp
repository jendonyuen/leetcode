class Solution {
public:
    string makeGood(string s) {
        int d = 'a' - 'A';
        while (true) {
            bool b = true;
            string cur;
            for(int i = 0; i < s.size(); ++i) {
                if (i < s.size() - 1 && (s[i+1] - s[i] == d || s[i] - s[i+1] == d)) {
                    b = false;
                    i++;
                } else {
                    cur.push_back(s[i]);
                }
            }
            s = cur;
            if (b) break;
        }
        
        return s;
    }
};