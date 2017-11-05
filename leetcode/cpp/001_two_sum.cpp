/*

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if ( dic.find(target - nums[i]) != dic.end() ) {
                ans.push_back(i);
                ans.push_back(dic[target - nums[i]]);
                return ans;
            }
            dic[nums[i]] = i;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};
