/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var ans = [0, 0];
    var map = {};
    for (var i = 0; i < nums.length; i++) {
        var tmp = target - nums[i];
        if (typeof map[tmp] != "undefined") {
            ans[0] = map[tmp];
            ans[1] = i;
            return ans;
        } else {
            map[nums[i]] = i;
        }
    }
    return ans;
};
