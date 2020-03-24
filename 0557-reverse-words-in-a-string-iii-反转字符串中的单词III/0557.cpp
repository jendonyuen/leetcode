class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        stack<char> word;
        for (auto &c: s) {
            if (c != ' ') {
                word.push(c);
            } else {
                while(!word.empty()) {
                    ans.push_back(word.top());
                    word.pop();
                }
                ans.push_back(' ');
            }
        }
        while(!word.empty()) {
            ans += word.top();
            word.pop();
        }
        return ans;
    }
};