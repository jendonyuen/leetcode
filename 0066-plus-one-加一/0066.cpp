class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto i = digits.end() - 1;
        bool isCarray = false;
        while (true) {
            (*i)++;
            if (*i == 10) {
                *i = 0;
                if (i != digits.begin()) {
                    i--;
                } else {
                    vector<int> d = {1};
                    for (auto &t: digits) {
                        d.push_back(t);
                    }
                    return d;
                }
            } else {
                break;
            }
        }
        return digits;
    }
};