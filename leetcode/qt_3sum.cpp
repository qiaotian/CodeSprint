/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-07-08T13:53:55+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-07-08T14:00:12+08:00
* @Difficulty: Medium
*/



Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if(len<3) return result;
        sort(nums.begin(), nums.end());

        for(int i=0; i<len-2; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue; // 'i>0' is for the case [0, 0, 0]
            int lft = i+1;
            int rgt = nums.size()-1;
            while(lft<rgt) {
                if(nums[lft]+nums[rgt]+nums[i]>0) {
                    rgt--;
                } else if(nums[lft]+nums[rgt]+nums[i]<0) {
                    lft++;
                } else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lft]);
                    temp.push_back(nums[rgt]);
                    result.push_back(temp);
                    while(lft<rgt && nums[lft]==nums[lft+1]) lft++;
                    while(lft<rgt && nums[rgt]==nums[rgt-1]) rgt--;
                    lft++; // should not be ignored
                    rgt--;
                }
            }

        }
        return result;
    }
};
