class Solution {
public:
    int minArray(vector<int>& numbers) {
        int beg = 0, end = numbers.size() - 1;
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (numbers[mid] < numbers[end]) {
                end = mid;
            } else if (numbers[mid] > numbers[end]) {
                beg = mid + 1;
            } else {
                end--;
            }
        }
        return numbers[beg];
    }
};