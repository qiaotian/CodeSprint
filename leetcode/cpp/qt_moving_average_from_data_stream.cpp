/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-03T10:27:00+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T10:42:31+08:00
* @License: Free License
* @Inc: Google
*/

/**
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> que;
    int capacity = 0; // 最大容量
    long long sum = 0;
    MovingAverage(int size) {
        capacity = size;
    }

    double next(int val) {
        if(que.size()==capacity) {
            sum = sum-que.front()+val;
            que.pop();
            que.push(val);
            return 1.0*sum/capacity;
        } else {
            sum += val;
            que.push(val);
            return 1.0*sum/que.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
