// 使用max-heap最大堆的性质

using std::make_heap;
using std::pop_heap;
using std::push_heap;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while(stones.size() > 1) {
            pop_heap(stones.begin(), stones.end());
            auto stone1 = stones.back();
            stones.pop_back();
            pop_heap(stones.begin(), stones.end());
            auto stone2 = stones.back();
            stones.pop_back();
            stone1 = stone2 - stone1;
            if (stone1 < 0) stone1 = - stone1;
            stones.push_back(stone1);
            push_heap(stones.begin(), stones.end());
        }
        // for (auto &a : stones) {
        //     cout << a << ",";
        // }
        // cout << endl;
        if (stones.size() > 0) {
            return stones[0];
        }
        return 0;
    }
};