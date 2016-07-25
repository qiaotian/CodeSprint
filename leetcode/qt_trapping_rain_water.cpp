/**
* @Author: Tian Qiao
* @Date:   2016-07-26T02:58:28+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-26T02:58:40+08:00
* @Inc: Google, Bloomberg, Amazon, ...
* @Difficulty: Hard
*/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
// 使用栈(2N)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for(int i=0; i<height.size(); i++) {
            if(s.empty() || height[i] <= height[s.top()]) s.push(i);
            else {
                int idx = s.top(); s.pop();
                while(!s.empty() && height[i] > height[idx]) {
                    // 注意：宽度是i-s.top()+1，非i-idx，也不是s.top()-idx
                    // 原因在于s.top(), idx, 和i三者均不连续的情况下，后面两个会是实际宽度的严格子集
                    if(height[i] <= height[s.top()]) ans += (height[i]-height[idx])*(i-s.top()-1);
                    else ans += (height[s.top()]-height[idx])*(i-s.top()-1);
                    idx = s.top(); s.pop();
                }
                if(height[i] <= height[idx]) s.push(idx);
                s.push(i);
            }
        }
        return ans;
    }
};

// 使用优先队列也能解决，对于一维没有必要使用


// 不使用栈(N) 双指针
// https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/18731/7-lines-c-c/2
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
