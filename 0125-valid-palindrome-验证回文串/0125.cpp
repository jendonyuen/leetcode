class Solution {
public:
    bool isPalindrome(string s) {
        // char c1 = 'A';
        // char c2 = 'Z';
        // char c3 = 'a';
        // char c4 = 'z';
        // char c5 = '0';
        // char c6 = '9';
        // cout << c1 - 0 << endl;
        // cout << c2 - 0 << endl;
        // cout << c3 - 0 << endl;
        // cout << c4 - 0 << endl;
        // cout << c5 - 0 << endl;
        // cout << c6 - 0 << endl;

        auto left = s.begin();
        auto right = s.end() - 1;
        while (left < right) {
            // 跳过符号
            while ( 
                !(
                    (*left >= 65 && *left <= 90)  ||
                    (*left >= 97 && *left <= 122) ||
                    (*left >= 48 && *left <= 57) ||
                    (left == right)
                )
            ) left++;
            while ( 
                !(
                    (*right >= 65 && *right <= 90)  ||
                    (*right >= 97 && *right <= 122) ||
                    (*right >= 48 && *right <= 57) ||
                    (left == right)
                )
            ) right--;
            // 统一大写
            if (*left >= 65 && *left <= 90) *left += 32;
            if (*right >= 65 && *right <= 90) *right += 32;
            
            if (*left != *right) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
};