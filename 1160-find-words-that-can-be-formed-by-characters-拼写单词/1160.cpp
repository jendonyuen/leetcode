class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int length = 0;
        for (const auto &word: words) {
            string temp = chars;
            bool isFormed = true;
            for (const auto &c: word) {
                int i = 0;
                for(; i != temp.size(); ++i) {
                    if (c == temp[i]) break;
                }
                if (i != temp.size()) {
                    temp.erase(i, 1);
                } else {
                    isFormed = false;
                    break;
                }
            }
            if (isFormed) {
                length += word.size();
            }
        }
        return length;
    }
};