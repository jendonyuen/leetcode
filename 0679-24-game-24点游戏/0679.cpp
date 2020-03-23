class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        for (int a = 0; a != nums.size(); ++a) {
            for (int b = a + 1; b != nums.size(); ++b) {
                // 第一次计算
                vector<float> v1;
                v1.push_back(nums[a] + nums[b]);
                v1.push_back(nums[a] - nums[b]);
                v1.push_back(nums[b] - nums[a]);
                v1.push_back(nums[a] * nums[b]);
                v1.push_back((float)nums[a] / (float)nums[b]);
                v1.push_back((float)nums[b] / (float)nums[a]);
                for (auto &t1: v1) {
                    // 第二次计算，有两种
                    for (int c = 0; c != nums.size(); ++c) {
                        // 1. 以第一次计算的结果为这次计算的其中一元，剩下的两个数取一个作为计算的另一元
                        if (c == a || c == b) continue;
                        vector<float> v2;
                        v2.push_back(nums[c] + t1);
                        v2.push_back(nums[c] - t1);
                        v2.push_back(t1 - nums[c]);
                        v2.push_back(nums[c] * t1);
                        v2.push_back(nums[c] / t1);
                        v2.push_back(t1 / nums[c]);
                        for (auto &t2: v2) {
                            for (int d = 0; d != nums.size(); ++d) {
                                // 第三次计算
                                if (d == a || d == b || d == c) continue;
                                if (nums[d] + t2 > 23.99 && nums[d] + t2 < 24.01) return true;
                                if (nums[d] - t2 > 23.99 && nums[d] - t2 < 24.01) return true;
                                if (t2 - nums[d] > 23.99 && t2 - nums[d] < 24.01) return true;
                                if (nums[d] * t2 > 23.99 && nums[d] * t2 < 24.01) return true;
                                if (nums[d] / t2 > 23.99 && nums[d] / t2 < 24.01) return true;
                                if (t2 / nums[d] > 23.99 && t2 / nums[d] < 24.01) return true;
                            }
                        }

                        // 2. 用剩下的两个数进行计算
                        for (int d = 0; d != nums.size(); ++d) {
                            if (d == a || d == b || d == c) continue;
                            vector<float> v2_;
                            v2_.push_back(nums[c] + nums[d]);
                            v2_.push_back(nums[c] - nums[d]);
                            v2_.push_back(nums[d] - nums[c]);
                            v2_.push_back(nums[c] * nums[d]);
                            v2_.push_back(float(nums[c]) / float(nums[d]));
                            v2_.push_back(float(nums[d]) / float(nums[c]));
                            for (auto &t2: v2_) {
                                // 第三次计算'
                                if (t1 + t2 > 23.99 && t1 + t2 < 24.01) return true;
                                if (t1 - t2 > 23.99 && t1 - t2 < 24.01) return true;
                                if (t2 - t1 > 23.99 && t2 - t1 < 24.01) return true;
                                if (t1 * t2 > 23.99 && t1 * t2 < 24.01) return true;
                                if (t1 / t2 > 23.99 && t1 / t2 < 24.01) return true;
                                if (t2 / t1 > 23.99 && t2 / t1 < 24.01) return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};