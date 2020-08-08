class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        stack<int> st;
        int t = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (t == 1) {
                    res++;  // insert ")"
                    t = 0;
                    st.pop();
                }
                st.push(0);
            } else {    // s[i] == ')'
                if (!st.empty()) {
                    t++;
                    if (t == 2) {
                        st.pop();
                        t = 0;
                    }
                } else {
                    st.push(0);
                    res++;  // found ")", but no "(", so insert "("
                    t++;
                }
                
            }
        }
        if (t == 1) {
            t = 0;
            res++;  // insert ")"
            st.pop();
        }
        while (!st.empty()) {
            st.pop();
            res += 2;
        }
        return res;
    }
};