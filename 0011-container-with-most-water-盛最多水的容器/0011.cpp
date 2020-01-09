class Solution {
public:
    int maxArea(vector<int>& height) {
        int vmax=0,vtemp = 0;
        for(int i = 0;i!=height.size()-1;++i){
            for(int j = i+1;j!=height.size();++j){
                vtemp = min(height[i],height[j])*(j-i);
                if(vtemp>vmax){
                    vmax = vtemp;
                }
            }
        }
        return vmax;
    }
};