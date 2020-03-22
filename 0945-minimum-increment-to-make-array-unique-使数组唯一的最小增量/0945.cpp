class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int n = 0;
        int nums[80000] = {0};

        for (auto &a: A) {
            nums[a]++;
        }

        int p = 0;
        for (int i = 0; i != 40000; ++i) {
            while (nums[i] > 1) {
                int p = i + 1;
                while(nums[p] != 0) p++;
                nums[p] = 1;
                n += p - i;
                nums[i]--;
            }
        }
        return n;
    }
    /* 超时 
    // 测试用例通过56/59
    int minIncrementForUnique(vector<int>& A) {
        int n = 0;
        unordered_map<int, int> nums;
        for (auto a : A) {
            if (nums.find(a) == nums.end()) {
                nums[a] = 1;
            } else {
                n++;
                while(nums.find(++a) != nums.end()) n++;
                nums[a] = 1;
            }
        }
        return n;
    }
    */
};