// 2020-06-19
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(right > left) {
            if (
                !(s[left] >= 'a' && s[left] <= 'z') &&
                !(s[left] >= 'A' && s[left] <= 'Z') &&
                !(s[left] >= '0' && s[left] <= '9')
            ) {
                left++;
                continue;
            }
            if (
                !(s[right] >= 'a' && s[right] <= 'z') &&
                !(s[right] >= 'A' && s[right] <= 'Z') &&
                !(s[right] >= '0' && s[right] <= '9')
            ) {
                right--;
                continue;
            }
            if (s[left] >= 'A' && s[left] <= 'Z') {
                s[left] += 'a' - 'A';
            }
            if (s[right] >= 'A' && s[right] <= 'Z') {
                s[right] += 'a' - 'A';
            }
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

/* 2020-03-18
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
*/