/**
* @Author: Tian Qiao
* @Date:   2016-07-28T00:03:57+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-28T00:03:59+08:00
* @Inc: Google
* @Difficulty: Hard
* @Tag: Heap
*/



/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
*/

// 5月15日第一次解
class MedianFinder {
public:
    priority_queue<int> minHeap;
    priority_queue<int, std::vector<int>, std::greater<int> > maxHeap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(minHeap.empty()) {
            minHeap.push(num);
            return;
        }
        if(maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if(num > minHeap.top()) minHeap.push(num);
        else if(num < maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        while(minHeap.size() >= maxHeap.size()+2) {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
        while(maxHeap.size() >= minHeap.size()+2) {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push_back(temp);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(minHeap.empty() && maxHeap.empty()) return -1;
        if(minHeap.empty()) return maxHeap.top();
        if(maxHeap.empty()) return minHeap.top();

        if(minHeap.size()==maxHeap.size()) return (minHeap.top()+maxHeap.top())/2;
        else if(minHeap.size() > maxHeap.size()) return minHeap.top();
        else return maxHeap.top();
    }
};


// 7月28日第二次解 beats 97.3%
// 注意判定条件的严密性
class MedianFinder {
public:
    priority_queue<int> greatHeap; // 大根堆
    priority_queue<int, vector<int>, std::greater<int>> smallHeap; // 小根堆
    // Adds a number into the data structure.
    void addNum(int num) {
        int m = greatHeap.size();
        int n = smallHeap.size();

        if(m==0 || num >= greatHeap.top()) smallHeap.push(num);
        else if(n==0 || num <= smallHeap.top()) greatHeap.push(num);

        // 平衡两个堆的元素个数
        int cnt1 = greatHeap.size();
        int cnt2 = smallHeap.size();

        if(cnt1-2>=cnt2) {
            smallHeap.push(greatHeap.top());
            greatHeap.pop();
        }
        else if(cnt1<=cnt2-2) {
            greatHeap.push(smallHeap.top());
            smallHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int cnt1 = greatHeap.size();
        int cnt2 = smallHeap.size();

        double top1 = greatHeap.empty()?0:(double)greatHeap.top();
        double top2 = smallHeap.empty()?0:(double)smallHeap.top();

        if((cnt1+cnt2)%2) return cnt1>cnt2?top1:top2;
        else return (top1+top2)/2.0;
    }
};

// Shorter
// https://discuss.leetcode.com/topic/27521/short-simple-java-c-python-o-log-n-o-1/2
// 解题思路(基本一致)：
// Keepint two heaps (or priority queues):
// Max-heap small has the smaller half of the numbers.
// Min-heap large has the larger half of the numbers.
// This gives me direct access to the one or two middle values (they're the tops of the heaps), so getting the median takes O(1) time. And adding a number takes O(log n) time.
class MedianFinder {
private:
    priority_queue<long> small, large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size()
               ? small.top()
               : (small.top() - large.top()) / 2.0;
    }
};
