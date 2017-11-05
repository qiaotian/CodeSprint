/*

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) {
            if (dic[target - nums[i]]) return vector<int> ans(nums[i], target - nums[i]);
            dic[target - nums[i]] = nums[i];
        }
        return return vector<int> ans(-1, -1);
    }
};
