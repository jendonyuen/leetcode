using std::make_heap;
using std::pop_heap;
using std::greater;


class KthLargest {
private:
    int k;
    vector<int> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        make_heap(nums.begin(), nums.end(), greater<>());
        while (nums.size() > k) {
            pop_heap(nums.begin(), nums.end(), greater<>());
            nums.pop_back();
        }
        this->k = k;
        this->nums = nums;
    }
    
    int add(int val) {
        if (nums.size() < k) {
            nums.push_back(val);
            push_heap(nums.begin(), nums.end(), greater<>());
            return nums[0];
        }
        if (val <= nums[0]) {
            return nums[0];
        } else {
            pop_heap(nums.begin(), nums.end(), greater<>());
            nums.pop_back();
            nums.push_back(val);
            push_heap(nums.begin(), nums.end(), greater<>());
            return nums[0];
        }
        return val;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */