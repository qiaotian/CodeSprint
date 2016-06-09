/**
* @Author: Tian Qiao <root>
* @Date:   2016-06-09T16:23:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-09T17:33:54+08:00
* @License: DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
*/

/**
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Given [3, 1, 5, 8]
Return 167
*/


// Time Complexity: O(N!)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return nums[0]*nums[1]+max(nums[0], nums[1]);

        int ans = INT32_MIN;
        for(int i=0; i<nums.size(); i++) {
            vector<int> tmp(nums);
            tmp.erase(tmp.begin()+i); //
            if(i==0) {
                ans = max(ans, nums[0]*nums[1]+maxCoins(tmp));
            } else if(i==nums.size()-1) {
                ans = max(ans, nums[nums.size()-2]*nums[nums.size()-1]+maxCoins(tmp));
            } else {
                ans = max(ans, nums[i-1]*nums[i]*nums[i+1]+maxCoins(tmp));
            }
        }
        return ans;
    }
};

// Time Complexity: O(N^3)
class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int _nums[nums.size() + 2];
        int n = 1;
        // delete all zeros in nums
        for (int x : nums) if (x > 0) _nums[n++] = x;
        // add 1 to head and tail of nums
        _nums[0] = _nums[n++] = 1;

        // dp[i][j] means the max coins could get by bursting all ballons between ith and jth elements
        int dp[n][n] = {};
        for (int k = 2; k < n; ++k) {
            // k is the distance between left and right
            // there is at least one element between left and right
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                // if ith balloon is the last balloon to be busrted,
                // calculate the coins and then update the dp[left][right]
                for (int i = left + 1; i < right; ++i)
                    dp[left][right] = max(dp[left][right], _nums[left]*_nums[i]*_nums[right] + dp[left][i]+dp[i][right]);
            }
        }
        return dp[0][n - 1];
    }
};

// Reference:
// https://leetcode.com/discuss/72216/share-some-analysis-and-explanations
