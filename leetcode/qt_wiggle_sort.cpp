/**
* @Author: Tian Qiao
* @Date:   2016-07-04T11:06:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-04T11:10:41+08:00
* @Inc: Google
* @Difficulty: Medium
*/

/*

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

*/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool flag = true; // ascending order
        for(int i=0; i<(int)nums.size()-1; i++) {
            if((flag && nums[i]>nums[i+1]) ||\
               (!flag && nums[i]<nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
            flag=!flag;
        }
    }
};
