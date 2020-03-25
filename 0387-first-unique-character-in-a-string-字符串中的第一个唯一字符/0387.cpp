class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> table(26, -1);
        vector<bool> uniqS(s.size(), false);

        for (int i = 0; i != s.size(); ++i) {
            if (table[s[i] - 'a'] == -1) {
                table[s[i] - 'a'] = i;
            } else {
                uniqS[i] = true;
                uniqS[table[s[i] - 'a']] = true;
            }
        }

        for (int i = 0; i != uniqS.size(); ++i) {
            if (uniqS[i] == false) {
                return i; 
            }
        }

        return -1;
    }
};