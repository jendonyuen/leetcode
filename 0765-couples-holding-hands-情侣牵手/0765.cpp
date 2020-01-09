class Solution {
    inline bool isCouple(vector<int>& row, int a, int b) {
        if (row[a] % 2 == 0) {
            if (row[a] == row[b] - 1) {
                return true;
            } else {
                return false;
            }
        } else {
            if (row[a] == row[b] + 1) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
    inline void swap(vector<int>& row, int swapIndex) {
        for (int i = swapIndex + 2; i < row.size(); i++) {
            if (isCouple(row, swapIndex, i)) {
                int temp = row[swapIndex + 1];
                row[swapIndex + 1] = row[i];
                row[i] = temp;
                break;   
            } 
        }
    }
    inline void log(vector<int> &row) {
        for (auto &a: row) {
            std::cout << a << ",";
        }
        std::cout << std::endl;
    }
public:
    int minSwapsCouples(vector<int>& row) {
        int swapTimes = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (!isCouple(row, i, i+1)) {
                swap(row, i);
                swapTimes++;
                // log(row);
            }   
        }
        return swapTimes;
    }
};