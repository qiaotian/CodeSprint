/**
* @Author: Tian Qiao
* @Date:   2016-07-03T15:28:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-03T15:42:33+08:00
* @Inc: So many
* @Difficulty: Easy
*/



Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

________________________________________________________________________________

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> hashmap; // from num to index
        for(int i=0; i<nums.size(); i++) {
            if(hashmap.find(nums[i]) != hashmap.end()) {
                ret.push_back(hashmap[nums[i]]);
                ret.push_back(i);
                return ret;
            }
            hashmap[target-nums[i]] = i;
        }
        return ret;
    }
};
