/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-09T11:15:02+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-09T11:17:43+08:00
* @Inc: Palanir, Facebook
* @Difficulty: Medium
*/


/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) nums[i]+=(i==0?0:nums[i-1]);
        unordered_map<int, int> dict; // key to its position
        for(int i=0; i<nums.size(); i++) {
            auto search = dict.find(nums[i]-k);
            if(search!=dict.end()) ans = max(ans, i-search->second);
            if(nums[i]==k) ans = max(ans, i+1);
            
            if(dict.find(nums[i])==dict.end()) dict[nums[i]] = i;
        }
        return ans;
    }
};
