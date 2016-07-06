/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T15:44:37+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T15:47:07+08:00
* @Inc: Airbnb, Palantir, Yahoo
*/


Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<2) return false;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; ++i) {
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};
