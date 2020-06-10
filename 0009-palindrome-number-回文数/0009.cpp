// 不转字符串
// 12321
// x = 12 y = 123
// x == y / 10
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int y = 0;
        while (x > y) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return x == y || x == y / 10;
    }
};

/*
// 转字符串
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int left = 0;
        int right = s.size() - 1;
        while(right > left) {
            if(s[right] != s[left]) return false;
            right--;
            left++;
        }
        return true;
    }
};
*/