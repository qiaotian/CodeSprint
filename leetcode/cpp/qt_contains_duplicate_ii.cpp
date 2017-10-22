/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-06T15:44:25+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-06T20:23:10+08:00
* @Inc: Palantir, Airbnb
* @Difficulty: Easy
*/


Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. (at most k+1 elements between ith and jth, including ith and jth eletments)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Solution One
        /*
        set<int> cand;
        for(int i=0; i<nums.size(); ++i) {
            if(i>k) cand.erase(nums[i-k-1]);
            if(!cand.insert(nums[i]).second) return true;
        }
        return false;
        */

        unordered_set<int> s;//最大容量为k的容器

        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i - k - 1]);//删 保持set中最多保持最新的k个元素
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);//增
        }

        return false;
    }
};

/***
 * Solution One (slow)
 *   ### std::pair<iterator,bool> insert( const value_type& value ) ####
 *   Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
 * Solution Two ()
 * /
