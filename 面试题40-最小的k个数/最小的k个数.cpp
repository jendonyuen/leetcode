using std::make_heap;
using std::pop_heap;
using std::greater;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> rtn;
        make_heap(arr.begin(), arr.end(), greater<>());
        for (int i = 0; i != k; ++i) {
            pop_heap(arr.begin(), arr.end(), greater<>());
            rtn.push_back(arr.back());
            arr.pop_back();
        }
        return rtn;
    }
};