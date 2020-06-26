class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> um;
        vector<vector<string>> res;
        for (auto &word: strs) {
            string code = "00000000000000000000000000";
            for (auto &c: word) {
                code[c - 'a']++;
            }
            // printf("%s \n", code.c_str());
            if (um.find(code) == um.end()) {
                um[code] = res.size();
                res.push_back({word});
            } else {
                res[um[code]].push_back(word);
            }
        }
        return res;
    }
};

/*
class Solution {
    string encode(vector<int> &v, int len) {
        string res;
        for (auto &n : v) {
            string s = to_string(n);
            for (int i = s.size(); i < len; i++) {
                res.push_back('0');
            }
            res += s;
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> um;
        vector<vector<string>> res;
        for (auto &word: strs) {
            vector<int> vWord(26, 0);
            for (auto &c: word) {
                vWord[c - 'a']++;
            }
            // 同个单词, 每个字母最多出现99次
            // string code = encode(vWord, 2);
            string code = encode(vWord, 1);
            if (um.find(code) == um.end()) {
                um[code] = res.size();
                res.push_back({word});
            } else {
                res[um[code]].push_back(word);
            }
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, int> um;
        vector<vector<string>> res;
        for (auto &word: strs) {
            vector<int> vWord(26, 0);
            for (auto &c: word) {
                vWord[c - 'a']++;
            }
            if (um.find(vWord) == um.end()) {
                um[vWord] = res.size();
                res.push_back({word});
            } else {
                res[um[vWord]].push_back(word);
            }
        }
        return res;
    }
};
*/