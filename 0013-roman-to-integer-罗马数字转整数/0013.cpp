class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        auto size = s.size();

        auto pos = s.find("CM");
        if (pos != s.npos) {
            ans += 900;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }
        pos = s.find("CD");
        if (pos != s.npos) {
            ans += 400;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }
        pos = s.find("XC");
        if (pos != s.npos) {
            ans += 90;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }
        pos = s.find("XL");
        if (pos != s.npos) {
            ans += 40;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }
        pos = s.find("IX");
        if (pos != s.npos) {
            ans += 9;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }
        pos = s.find("IV");
        if (pos != s.npos) {
            ans += 4;
            s = s.substr(0, pos) + s.substr(pos + 2, size - pos - 2);
        }

        
        while(true) {
            pos = s.find("M");
            if (pos == s.npos) break;
            ans += 1000;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("D");
            if (pos == s.npos) break;
            ans += 500;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("C");
            if (pos == s.npos) break;
            ans += 100;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("L");
            if (pos == s.npos) break;
            ans += 50;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("X");
            if (pos == s.npos) break;
            ans += 10;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("V");
            if (pos == s.npos) break;
            ans += 5;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }
        while(true) {
            pos = s.find("I");
            if (pos == s.npos) break;
            ans += 1;
            s = s.substr(0, pos) + s.substr(pos + 1, size - pos - 1);
        }

        return ans;
    }
};