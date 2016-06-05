/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-02-28T01:10:56+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-06-06T00:20:06+08:00
* @License: DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
*/


/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i-1]+nums[i], nums[i]);
            res = max(res, nums[i]);
        }
        return res;
    }
};
*/

// 8ms beats 70%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], cur = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * 1st solution
 * Space: O(N)
 *
 * 2nd solution
 * Space: O(1)
 * /
