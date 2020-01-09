class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for(auto a: nums){
            if(a==target){
                return index;
            }else if(a>target){
                return index;
            }else{
                ++index;
            }
        }
        return index;
    }
};