/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

/*
class MinStack {
    vector<int> vec;
    vector<int> min;
public:
    MinStack() {
        min.push_back(2147483647); // max int
    }
    void push(int x) {
        vec.push_back(x);
        if(x < min.back())
            min.push_back(x);
        else
            min.push_back(min.back());
    }

    void pop() {
        vec.pop_back();
        min.pop_back();
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        return min.back();
    }
};
*/

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);       
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};

/**
 * All these method will use two containers 
 * including one for minimal value
 */

// 改进：将空间复杂度降到O(1)
// The current min among the stack elements.
// For each pushed element, the difference to the previous min. If the pushed element changes min, because it is even smaller, then this difference is negative. If it's larger than the previous min, then the difference is positive.
// For pop, I need to pop the last difference and undo its change to min (if any). For top, I need to add the current min and the last difference (if it's positive, i.e., if the last element was larger than the minimum).

class MinStack {
private:
    long long minval;
    vector<long long> vec;
public:
    MinStack() {
        minval = INT32_MAX;
    }
    void push(int x) {
        vec.push_back((long long)x-minval); // x极小且minmal极小，很容易溢出
        minval = min((long long)x, minval);
    }
    void pop() {
        long long tmp = vec.back();
        minval -= min(tmp, (long long)0); 
        vec.pop_back();
    }
    int top() {
        return max(vec.back(), (long long)0)+minval;
    }
    int getMin(){
        return minval;
    }
};
