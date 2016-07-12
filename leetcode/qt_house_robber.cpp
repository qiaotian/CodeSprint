/**
* @Author: Tian Qiao <root>
* @Date:   2016-07-12T14:25:45+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-07-12T14:27:25+08:00
* @Inc: LinkedIn, Airbnb
* @Difficulty: Easy
*/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/


class Solution {
public:
    // 1st Solution (Time Limit Exceeded)
    /*
    int robUtil(vector<int>& nums, int start, int end) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        if(start+1 == end) return max(nums[start], nums[start+1]);
        if(start+2 == end) return max(nums[start] + nums[start+2], nums[start+1]);

        return max(nums[start]+robUtil(nums, start+2, end), robUtil(nums, start+1, end));
    }
    int rob(vector<int>& nums) {
        return robUtil(nums, 0, nums.size()-1);
    }
    */
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int pre = 0, cur = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int tmp = cur;
            cur = max(pre+nums[i], cur);
            pre = tmp;
        }
        return cur>pre?cur:pre;
    }
};
