class Solution {
public:
    vector<string> v = {};
    void push(string s) {
        if (v.size() == 0) {
            for (auto a : s) {
                string st(1,a);
                v.push_back(st);
            }
            return;
        }
        vector<string> vtemp = v;
        v.clear();
        for (auto a : s) {
            for (auto b : vtemp) {
                    b.push_back(a);
                    v.push_back(b);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        for (auto &a : digits) {
            if (a == '2') {
                push("abc");
            }else if(a == '3') {
                push("def");
            }else if(a == '4') {
                push("ghi");
            }else if(a == '5') {
                push("jkl");
            }else if(a == '6') {
                push("mno");
            }else if(a == '7') {
                push("pqrs");
            }else if(a == '8') {
                push("tuv");
            }else if(a == '9') {
                push("wxyz");
            }
        }   
        return v;
    }
};