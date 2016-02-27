// 8ms beats 70%
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
