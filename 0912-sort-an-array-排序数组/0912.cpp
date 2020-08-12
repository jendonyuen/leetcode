// 2020-08-11 update
// 随机划分快排
// ref: https://leetcode-cn.com/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l;      // 双指针, i指向待交换的元素, 确保i之前的元素都小于主元(从小到大排序)
        for (int j = l; j <= r - 1; ++j) {  
            if (nums[j] <= pivot) {          // 如果当前元素小于主元, 将其放置i位置
                swap(nums[i], nums[j]);     
                i++;
            }
        }
        swap(nums[i], nums[r]); // 将主元放在i位置, 这时i左边的必定小于等于i, i右边的必定大于等于i
        return i;
    }

    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;   // 从[l, r]之间随机选择一个主元
        swap(nums[r], nums[i]);             // 将其与最右位置的元素交换
        return partition(nums, l, r);
    }

    // 快排是典型的分治算法
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pos = randomized_partition(nums, l, r);
        randomized_quicksort(nums, l, pos - 1);
        randomized_quicksort(nums, pos + 1, r);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

/*
ref: https://leetcode-cn.com/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
堆排序
用数组建堆, 数组索引按树的从上往下, 从左往右排布
*/
class Solution {
    // 对i结点进行堆化(前提是i的子节点以后的元素均已堆化)
    void heapify(vector<int>& nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {  // 访问[i]节点的左子节点和右子节点
            int lson = (i << 1) + 1;    // left child
            int rson = (i << 1) + 2;    // right child
            int large;                  // 将large指向i, lson, rson三个中最大的元素
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            } else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            
            if (large != i) {               // 如果i节点不是值最大的元素
                swap(nums[i], nums[large]); // 通过交换, 将i节点改为值最大(大根堆)的元素 
                i = large;                  // 交换后, 可能破坏堆的性质, 递归调用, 树转移至下一层
            }
            else break;
        }
    } 

    // 建堆
    void buildHeap(vector<int>& nums) {
        int len = nums.size() - 1;
        // 从下往上建堆, 起点为最后一个非叶子节点(len/2)
        for (int i = len >> 1; i >= 0; --i) {
            heapify(nums, i, len);
        }
    }

    // 堆排序, 依次将堆顶元素放到末尾, 剩余元素重新堆化
    void sortHeap(vector<int>& nums) {
        int len = nums.size() - 1;          // len指向末尾
        for (int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);         // 将堆顶元素交换至len位置
            len -= 1;
            heapify(nums, 0, len);          // 对堆顶元素重新堆化
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        buildHeap(nums);
        sortHeap(nums);
        return nums;
    }
};

// old
class Solution {
    // 快速排序法
    void quickSort(vector<int>& nums, int beg, int end) {
        if (end <= beg) return;
        int i = beg, j = end + 1;
        int key = nums[beg];

        while (true) {
            // 从左往右找比key大的元素索引
            while (nums[++i] < key && i != end);
            // 从右往左找比key小的元素索引
            while (nums[--j] > key && j != beg);
            // 当两个指针相遇时终止
            if (i >= j) break;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        // 交换key与j对应值
        int temp = nums[beg];
        nums[beg] = nums[j];
        nums[j] = temp;
        // 递归前半部分和后半部分
        quickSort(nums, beg, j - 1);
        quickSort(nums, j + 1, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};