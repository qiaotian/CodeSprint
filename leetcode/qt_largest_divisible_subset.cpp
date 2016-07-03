/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-06-29T15:27:41+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-03T11:17:16+08:00
* @License: Free License
*/


/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.

Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8]
*/

class Solution {
public:
    bool isDvisibleSubset(vector<int>& nums, int start, int end) {
        int maxValue = nums[start];
        for(int i=start; i<end; i++) {
            if(nums[i]%maxValue==0 || nums[i]) {
                maxValue = max(maxValue, nums[i]);
            }
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {

    }
};
