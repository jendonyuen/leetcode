class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for (auto &&n : nums) {
            vs.push_back(to_string(n));
        }
        auto cmp = [](auto &&a, auto &&b) {
            return a+b > b+a;
        };
        sort(vs.begin(), vs.end(), cmp);
        string res;
        for (auto &&s : vs) {
            res.append(s);
        } 
        return res[0] == '0' ? "0" : res;
    }
};


/*
bool cmp(int& a, int& b) {
    string sa = to_string(a), sb = to_string(b);
    return sa+sb > sb+sa;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        for (auto &n : nums) {
            res += to_string(n);
        } 
        return res[0] == '0' ? "0" : res;
    }
};
*/