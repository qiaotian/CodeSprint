/*
Given an integer array, find the max two sum that the first element is smaller than the second element and the first occurs ahead the second. Suppose that there must be a answer for all cases.
*/

#include <vector>
#include <iostream>

int max_two_sum(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    vector<int> dp(n, INT_MIN); // 用于存放倒数前n个数的最小值
    dp[n-1] = nums[n-1]; //
    for(int i=n-2; i>=0; i++) {
        dp[i] = max(nums[i],dp[i+1]);
    }
    for(int i=0; i<n-2; i++) {
        if(nums[i]<dp[i+1]) {
            ans = max(ans, nums[i]+dp[i+1]);
        }
    }
    return ans;
}
