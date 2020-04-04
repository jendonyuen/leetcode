class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> v;
        int deep = -1;
        for (int i = 0; i != seq.size(); ++i) {
            if (seq[i] == '(') {
                deep++;
                if (deep % 2 == 0) v.push_back(0);
                else v.push_back(1);
            } else {
                deep--;
                if (deep % 2 == 0) v.push_back(1);
                else v.push_back(0);
            }
        }
        return v;
    }
};