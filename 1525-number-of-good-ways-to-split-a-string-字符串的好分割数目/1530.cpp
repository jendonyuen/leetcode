class Solution {
public:
    int numSplits(string s) {
        vector<int> toRight(s.size() + 1, 0);
        vector<int> toLeft(s.size() + 1, 0);
        unordered_set<char> toRightSet;
        unordered_set<char> toLeftSet;
        for (int i = 0; i < s.size(); ++i) {
            toRightSet.insert(s[i]);
            toRight[i+1] = toRightSet.size();
        }
        for (int j = s.size() - 1; j >= 0; --j) {
            toLeftSet.insert(s[j]);
            toLeft[j] = toLeftSet.size();
        }
        
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (toLeft[i] == toRight[i]) res++;
        }
        return res;
    }
};