class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.rfind(" ");
        if (i!= s.npos) {
            int ret = s.size() - i - 1;
            if(ret == 0 && i!= 0) {
                int j = s.find_last_not_of(" ");
                if (j!=s.npos) {
                    i = s.rfind(" ", j);
                    ret = j - i;
                }
            }
            return ret;
        } else {
            return s.size();
        }
    }
};