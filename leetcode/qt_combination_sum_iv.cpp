/**
* @Author: Tian Qiao
* @Date:   2016-07-26T01:29:31+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-26T01:29:46+08:00
*/



/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:
nums = [1, 2, 3], target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/

// TLE
class Solution {
public:
    void util(vector<int>& nums, int target, int sum, int& ans) {
        if(sum==target) ans++;
        if(sum>target) return;
        for(int i=0; i<nums.size(); i++) {
            util(nums, target, sum+nums[i], ans);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
        int ans = 0;
        util(nums, target, 0, ans);
        return ans;
    }
};

// DP
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // target[i]表示i为目标的组合数
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++) {
            for(auto k:nums) {
                dp[i] += i>=k?dp[i-k]:0;
            }
        }
        return dp[target];
    }
};
