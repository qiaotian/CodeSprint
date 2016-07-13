/**
* @Author: Tian Qiao
* @Date:   2016-07-13T17:54:56+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-13T17:55:37+08:00
* @Inc: Facebook
* @Difficulty: Medium
*/

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return -1;
        if(s==1) return 1;

        for(int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        int window = 1;
        while(nums[window-1] < s) window++; //

        int sum = nums[window-1];
        for(int i=0; i<nums.size()-window+1; i++) {
            if(sum+nums[i+window]-nums[i]>=s) {
                sum += nums[i+window]-nums[i];
                while(sum-nums[i+1]>=s) {
                    i++;
                    window--;
                }
                i--;
            }
        }
        return window;
    }
};
