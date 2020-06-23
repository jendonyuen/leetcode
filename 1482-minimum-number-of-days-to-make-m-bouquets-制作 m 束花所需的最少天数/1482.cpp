class Solution {
    int m;
    int k;
    inline bool search(vector<int>& bloomDay, int& beg, int& end) {
        int flowerNum = 0;
        int adjacent = 0;
        int mid = (beg + end) / 2;
        // cout << beg << "," << mid << "," << end << endl;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (flowerNum >= m) break;
            if (bloomDay[i] <= mid) {
                adjacent++;
                if (adjacent == k) {
                    adjacent = 0;
                    flowerNum++;
                }
            } else {
                adjacent = 0;
            }
        }
        if (flowerNum < m) {
            beg = mid + 1;
            return false;
        }
        end = mid;
        return true;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        this->m = m;
        this->k = k;
        int beg = INT_MAX;
        int end = INT_MIN;
        int maxDay;
        for (auto &a: bloomDay) {
            if (a < beg) beg = a;
            if (a > end) end = a;
        }
        maxDay = end;

        while(beg < end) {
            search(bloomDay, beg, end);
        }

        if (beg == maxDay) {
            if (search(bloomDay, beg, end)) {
                return beg;
            } else {
                return -1;
            }
        }

        return beg;
    }
};