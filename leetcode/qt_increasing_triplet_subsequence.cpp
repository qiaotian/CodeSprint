// 1st solution (576ms, beat 5%, DP)
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        vector<int> sublen(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    sublen[i] = max(sublen[j]+1, sublen[i]);
                    if(sublen[i] == 3) return true;
                }
            }
        }
        return false;
    }
};
*/

// 2nd solution () (4ms, beats 13%)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT32_MAX, mid = INT32_MAX;
        for(int i : nums) {
            if(i <= low) low = i;
            else if( i <= upper) mid = i;
            else return true;
        }
        return false;
    }
};

/**
 * WARNING:
 * Since this problem just requires a three elements subsequence, which is different from
 * the problem "Longest Increasing Subsequence".
 *
 * ALGO:
 * 1. 1st solution is inspired by the longest increasing subsequence, whose time comlexity is O(N^2).
 * 2. 2st solution is linear time complexity. In this method, we try our best to minimize the 'low' and 'mid',
 *    as we can find a high value more easily. Only if we find the 'high', then 'low < mid < high' is valid,
 *    therefore we can return true.
 *
 * REFERENCE:
 * https://leetcode.com/discuss/86593/clean-and-short-with-comments-c
 *
 * /
