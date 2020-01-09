class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::deque<int> q;
        std::deque<int> del;
        int i = 0;
        for (auto &a: s) {
            if (a == '(') {
                q.push_back(i); 
            } else if (a == ')') {
                if (q.empty() == true) {
                    del.push_back(i);
                } else {
                    q.pop_back();
                }
            }
            i++;
        }
        for (int i = q.size(); i != 0; --i) {
            s.erase(q[i-1], 1);
        }
        for (int i = del.size(); i != 0; --i) {
            s.erase(del[i-1], 1);
        }
        return s;
    }
};