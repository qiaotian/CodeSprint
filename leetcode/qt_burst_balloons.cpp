/**
* @Author: Tian Qiao <root>
* @Date:   2016-06-09T16:23:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   root
* @Last modified time: 2016-06-09T16:27:27+08:00
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

// Time Complexity: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
    }
};
~
