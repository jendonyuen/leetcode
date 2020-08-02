class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vnode1;  // 可跳跃的节点的坐标(nums1)
        vector<int> vnode2;  // 可跳跃的节点的坐标(nums2)
        unordered_map<int, int> um;
        nums1.push_back(0); // 哨兵
        nums2.push_back(0);
        for (int i = 0; i < nums1.size(); ++i) {
            um[nums1[i]] = i;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (um.count(nums2[i])) {
                vnode1.push_back(um[nums2[i]]);
                vnode2.push_back(i);
            }
        }
        
        
        int prev = -1;
        long long res = 0;
        for (int i = 0; i < vnode1.size(); ++i) {
            long long sum1 = 0;
            long long sum2 = 0;
            prev = i - 1 >= 0 ? vnode1[i-1] : -1;
            for (int j = prev + 1; j < vnode1[i]; ++j) {
                sum1 += nums1[j];
            }
            prev = i - 1 >= 0 ? vnode2[i-1] : -1;
            for (int j = prev + 1; j < vnode2[i]; ++j) {
                sum2 += nums2[j];
            }
            res += max(sum1, sum2) + nums1[vnode1[i]];
        }
        
        
        
        return fmod(res, 1000000007);
    }
};