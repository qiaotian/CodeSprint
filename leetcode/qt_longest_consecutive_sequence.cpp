/**
* @Author: Tian Qiao
* @Date:   2016-07-16T12:55:12+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   Tian Qiao
* @Last modified time: 2016-07-16T12:55:42+08:00
* @Inc: Google, Facebook
* @Difficulty: Hard
* @Tag: Array, Union-Find
*/


// hash table
// https://discuss.leetcode.com/topic/15383/simple-o-n-with-explanation-just-walk-each-streak
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> uset;
        for(auto i:nums) uset.insert(i);
        for(auto i:uset) {
            if(uset.find(i-1)==uset.end()) {
                int m = i+1;
                while(uset.find(m)!=uset.end()) m++;
                ans = max(ans, m-i);
            }
        }
        return ans;
    }
};
