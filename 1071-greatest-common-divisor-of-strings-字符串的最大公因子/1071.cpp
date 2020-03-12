class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // 使p指向较短的字符串长度
        int p = str1.size();
        if (str1.size() >= str2.size()) {
            p = str2.size();
        } 
        while (p != 0) {
            // 确保可整除
            if (str1.size() % p != 0 || str2.size() % p != 0) {
                p -= 1;
                continue;
            }

            bool isContinue = false;
            int q = 0;
            int i = 0;

            // 验证两个字符串公共部分
            for (; i!= p; i++) {
                if (str1[i] != str2[q]) {
                    isContinue = true;
                    break;
                }
                if (str1[i] != str2[q]) {
                    isContinue = true;
                    break;
                }
                if (++q >= p) q = 0;
            }
            if (isContinue) {
                p -= 1;
                continue;
            }

            // 验证较长字符串多出部分
            if (str1.size() >= str2.size()) {
                for (;i != str1.size(); i++) {
                    if (str1[i] != str1[q]) {
                        isContinue = true;
                        break;
                    }
                    if (++q >= p) q = 0;
                }
            } else {
                for (;i != str2.size(); i++) {
                    if (str2[i] != str2[q]) {
                        isContinue = true;
                        break;
                    }
                    if (++q >= p) q = 0;
                }
            }
            if (isContinue) {
                p -= 1;
                continue;
            }

            return str1.substr(0, p);
        }
        return "";
    }
};