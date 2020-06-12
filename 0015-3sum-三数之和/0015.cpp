class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            while(p1 < p2) {
                int sum = nums[i] + nums[p1] + nums[p2];
                if (sum == 0) {
                    res.push_back({nums[i], nums[p1], nums[p2]});
                    p1++;
                    while (p1 < p2 && nums[p1] == nums[p1-1]) p1++;
                } else if (sum < 0) {
                    p1++;
                    while (p1 < p2 && nums[p1] == nums[p1-1]) p1++;
                } else {
                    p2--;
                    while (p1 < p2 && nums[p2] == nums[p2+1]) p2--;
                }
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        
        if (nums.size() < 3) return v;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return v;
        
        
        int last = ~nums[0];
        for (int i = 0; i != nums.size() - 2; ++i) {
            if (last == nums[i]) continue;
            last = nums[i];
            if (nums[i] > 0) break;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    v.push_back({nums[i], nums[left], nums[right]});
                    // 自增
                    int temp = nums[left];
                    while(++left < right && nums[left] == temp);
                    temp = nums[right];
                    while(--right > left && nums[right] == temp);
                } else if (sum < 0) {
                    int temp = nums[left];
                    while(++left != right && nums[left] == temp);
                } else {
                    int temp = nums[right];
                    while(--right != left && nums[right] == temp);
                }
            }
        }
        
        return v;
    }
};

*/