// 30th biweekly contest
class Solution {
    unordered_map<string, string> month;
public:
    string reformatDate(string date) {
        // init month
        vector<string> vMonth = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < vMonth.size(); ++i) {
            string cur;
            if (i < 9) cur = "0";
            cur += to_string(i+1);
            month[vMonth[i]] = cur;
        }
        
        vector<string> res;
        string cur;
        for (int i = 0; i < date.size(); ++i) {
            if (date[i] == ' ') {
                if (res.size() == 0) {
                    if (cur.size() == 3) {
                        cur = "0" + cur.substr(0, 1);
                    } else {
                        cur = cur.substr(0, 2);
                    }
                } else if (res.size() == 1) {
                    cur = month[cur];
                }
                res.push_back(cur);
                cur = "";
            } else {
                cur.push_back(date[i]);
            }
        }
        res.push_back(cur);
        
        return res[2] + "-" + res[1] + "-" + res[0];
    }
};