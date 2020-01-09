class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 1;
        int temp =0;
        while(temp!=i){
            temp = i;
            for(auto a1:nums){
                if(a1==i){
                    ++i;
                }
            }
        }
        return i;
    }
};