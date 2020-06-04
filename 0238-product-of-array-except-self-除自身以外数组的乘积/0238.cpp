class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vl = nums, vr = nums;
        int cur = 1;
        for (auto &a: vl) {
            a *= cur;
            cur = a;
        } 
        cur = 1;
        for (int i = vr.size() - 1; i >= 0; --i) {
            vr[i] *= cur;
            cur = vr[i];
        } 
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int t = 1;
            if (i+1 < nums.size()) {
                t *= vr[i+1];
            }
            if (i-1 >= 0) {
                t *= vl[i-1];
            }
            ans.push_back(t);
        } 
        return ans;
    }
};