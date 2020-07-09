/*
ref: https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-sao-miao-xian-fa-by-ivan_al/
扫描线算法
利用c++ multiset排序特性:
当元素为pair时, 先依照pair.first进行排序, pair.first相同时依照pair.second进行排序;
用负值表示起始点, 依照上述排序特性, 高度高的起始点会先入堆, 矮的起始点后入堆, 矮的终止点先出堆, 高的终止点后出堆, 非常巧妙
*/


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> buildingSet;
        for (auto &bd: buildings) {
            buildingSet.insert(make_pair(bd[0], -bd[2]));   // 负值表示起始点
            buildingSet.insert(make_pair(bd[1], bd[2]));    // 正值表示终止点
        } 

        vector<vector<int>> res;
        multiset<int> heights = {0};    // 当前位置的高度
        int lastHeight = 0;
        for (auto &bdH: buildingSet) {
            if (bdH.second < 0) {       // 起始点入堆
                heights.insert(-bdH.second);    
            } else {                    // 终止点出堆
                heights.erase(heights.find(bdH.second));
            }
            
            if (*heights.rbegin() != lastHeight) {
                res.push_back({bdH.first, *heights.rbegin()});
                lastHeight = *heights.rbegin();
            }
        }

        return res;
    }
};