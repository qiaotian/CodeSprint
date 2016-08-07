/**
* @Author: Tian Qiao
* @Date:   2016-08-07T23:53:41+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-08-07T23:53:43+08:00
*/


/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++) {
            while ((nums[i] > 0) && (nums[i] <= numsSize) && (nums[i] != nums[nums[i] - 1])) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        //find missing number
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] != i + 1) return i+1;
        }

        return numsSize + 1;
    }
};
