/**
* @Author: Tian Qiao
* @Date:   2016-07-10T19:18:26+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-28T00:58:57+08:00
* @Inc: Microsoft
* @Difficulty: Medium
*/

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/

/*
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};
*/

// O(N)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) return nums[i];
        }
        return res;
    }
};

// O(logN) 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r) {
            // 因为l更新到m右边一位，因此有可能跳到递增区间上
            if (nums[l]<nums[r]) return nums[l];

            int m = (l+r)/2;
            if(nums[m]>=nums[l]) l = m+1; // l肯定在min的左边
            else if(nums[m]<nums[r]) r = m; // r在min的位置及右边
        }
        return nums[l];
    }
};
