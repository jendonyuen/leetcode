class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() == 1) return true;
        int p1 = 0, p2 = s.size() - 1;
        while (p1 < p2) {
            if (s[p1] != s[p2]) {
                int t1 = p1 + 1;
                int t2 = p2;
                while (t1 < t2) {
                    if (s[t1] != s[t2]) {break;}
                    t1++;
                    t2--;
                }
                if (t1 >= t2) {return true;}
                int t3 = p1;
                int t4 = p2 - 1;
                while (t3 < t4) {
                    if (s[t3] != s[t4]) {break;}
                    t3++;
                    t4--;
                } 
                if (t3 >= t4) {return true;}
                return false;
            } 
            p1++;
            p2--;
        }
        return p1 >= p2;
    }
};