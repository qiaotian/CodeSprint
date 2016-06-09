/**
* @Author: Tian Qiao <root>
* @Date:   2016-06-09T18:09:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-09T18:32:16+08:00
* @License: DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
*/



/**
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

cclass MedianFinder {
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

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
