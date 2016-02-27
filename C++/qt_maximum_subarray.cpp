ass Solution {
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
