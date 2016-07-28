/**
* @Author: Tian Qiao
* @Date:   2016-07-28T00:55:21+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-28T00:55:24+08:00
* @Inc: Unkown
* @Difficulty: Hard
*/


/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
*/


// 允许重复的条件下，nums[l]和nums[r]有可能相同，因此上一题中
// nums[l]<=nums[r]的判出条件不足
// 解决方案：首先寻找第一个大于nums[r]的nums[l]，如果找到，则
// 运用find_minimum_in_rotated_sorted_array中的方法
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        // find the first element that bigger than nums[r]
        while(l<r) {
            if(nums[l]>nums[l+1]) return nums[l+1]; // 处理case: [3,1,3]
            if(nums[l]<=nums[r]) l++;
            else break;
        }
        if(l==r) return nums[0]; // 异常处理

        // the same method with previous problem on new [l, r]
        while(l<r) {
            if(nums[l]<=nums[r]) return nums[l];

            int m = (l+r)/2;
            if(nums[m]>=nums[l]) l = m+1;
            else if(nums[m]<=nums[r]) r = m;
        }
        return nums[l];
    }
};
