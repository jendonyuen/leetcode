class MedianFinder {
    // left [1,2,3] | [4,5] right
    // left堆允许比right多1
    // 每次add将值加入left堆, 再做平衡
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        left.push(num);
        if (left.size() - right.size() > 1) {
            right.push(left.top());
            left.pop();
        } else if (!right.empty() && left.top() > right.top()) {
            int t = right.top();
            right.pop();
            right.push(left.top());
            left.pop();
            left.push(t);
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) return left.top(); 
        return (left.top() + right.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



// multiset + 单指针
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