class Solution {
    vector<string> res;
    string cur;

    bool checkLegal(string &s) {
        if (s.size() > 3) return false;                     // n < ***
        else if (s.size() == 3) {
            if (s[0] > '2' || s[0] == '0') return false;    // n < 2**
            if (s[0] == '2') {  
                if (s[1] > '5') return false;                   // n <= 25*
                if (s[1] == '5' && s[2] > '5') return false;    // n <= 255   
            }
        } else if (s.size() == 2 && s[0] == '0') return false;  // 00
        return true;
    }

    bool checkCur() {
        if (cur.empty()) return true;
        if (cur == ".") return false;
        string t;
        if (cur.back() != '.') t.push_back(cur.back());
        for (int i = cur.size() - 2; i >= 0; --i) {
            if (cur[i] == '.') {
                if (cur[i+1] == '.') return false;          // *..
                break;
            } else t = cur[i] + t;        
        }
        return checkLegal(t);
    }

    void backTrack(string& s, int i, int pNum) {
        if (i >= s.size()) {
            return;      // 索引指针超出范围, 返回
        }

        if (!checkCur()) {
            return;     // 当前部分不合法, 返回
        }

        // cout << i << ":   " << cur << endl;

        if (pNum >= 3) {                // 检查是否为合法的ip地址
            string l = s.substr(i, s.size() - i);
            if (checkLegal(l)) {
                res.push_back(cur + l); // 找到正确答案, 返回
            }
            return;
        }

        cur.push_back(s[i]);
        backTrack(s, i+1, pNum);
        cur.pop_back();

        cur.push_back('.');
        backTrack(s, i, pNum + 1);
        cur.pop_back();
    }
public:
    vector<string> restoreIpAddresses(string s) {
        backTrack(s, 0, 0);
        return res;
    }

    // test
    /*
    Solution() {
        cout << "==test==" << endl;
        string s = "100";
        cout << checkLegal(s) << endl;
        cout << "==test==" << endl;
    }
    */
};