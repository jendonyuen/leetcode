// multiset
/*
[1,2] 如果插入1, 必然会插入到原容器中1的右边
[1,(1),2]
*/
class MedianFinder {
    multiset<int> mts;
    multiset<int>::iterator mid;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        mts.insert(num);
        if (mts.size() == 1) {
            mid = mts.begin();
        } else if (mts.size() & 1) {
            if (num >= *mid) mid++;
        } else {
            if (num < *mid) mid--;
        }
    }
    
    double findMedian() {
        return mts.size() & 1 ? *mid : (*mid + *next(mid)) * 0.5;
    }
};

// 双堆法见第295题